namespace utils
{
    auto get_system_information(const SYSTEM_INFORMATION_CLASS information_class) -> const void*
    {
        unsigned long size = 32;
        char buffer[32];

        ZwQuerySystemInformation(information_class, buffer, size, &size);

        const auto info = ExAllocatePool(NonPagedPool, size);

        if (!info)
        {
            return nullptr;
        }

        if (ZwQuerySystemInformation(information_class, info, size, &size) != STATUS_SUCCESS)
        {
            ExFreePool(info);
            return nullptr;
        }

        return info;
    }

    auto get_kernel_module(const char* name) -> const uintptr_t
    {
        const auto to_lower = [](char* string) -> const char* {
            for (char* pointer = string; *pointer != '\0'; ++pointer)
            {
                *pointer = (char)(short)tolower(*pointer);
            }

            return string;
            };

        const auto info = (PRTL_PROCESS_MODULES)get_system_information(system_module_information);

        if (!info)
        {
            return 0;
        }

        for (auto i = 0ull; i < info->number_of_modules; ++i)
        {
            const auto& module = info->modules[i];

            if (strcmp(to_lower((char*)module.full_path_name + module.offset_to_file_name), name) == 0)
            {
                const auto address = module.image_base;

                ExFreePool(info);

                return reinterpret_cast<uintptr_t> (address);
            }
        }

        ExFreePool(info);

        return 0;
    }



    //from https://www.unknowncheats.me/forum/anti-cheat-bypass/444289-read-process-physical-memory-attach.html
    DWORD getoffsets()
    {
        RTL_OSVERSIONINFOW ver = { 0 };
        RtlGetVersion(&ver);

        switch (ver.dwBuildNumber)
        {
        case WINDOWS_1803:
            return 0x0278;
            break;
        case WINDOWS_1809:
            return 0x0278;
            break;
        case WINDOWS_1903:
            return 0x0280;
            break;
        case WINDOWS_1909:
            return 0x0280;
            break;
        case WINDOWS_2004:
            return 0x0388;
            break;
        case WINDOWS_20H2:
            return 0x0388;
            break;
        case WINDOWS_21H2:
            return 0x0388;
            break;
        case WINDOWS_22H2:
            return 0x0388;
            break;
        default:
            return 0x0388;
        }
    }

    auto getprocessdirbase(PEPROCESS targetprocess) -> ULONG_PTR
    {
        if (!targetprocess)
            return 0;

        PUCHAR process = (PUCHAR)targetprocess;
        ULONG_PTR process_dirbase = *(PULONG_PTR)(process + 0x28);
        if (process_dirbase == 0)
        {
            auto userdiroffset = getoffsets();
            ULONG_PTR process_userdirbase = *(PULONG_PTR)(process + userdiroffset);
            return process_userdirbase;
        }
        return process_dirbase;
    }

    auto readphysaddress(PVOID address, PVOID buffer, SIZE_T size, SIZE_T* read) -> NTSTATUS
    {
        if (!address)
            return STATUS_UNSUCCESSFUL;

        MM_COPY_ADDRESS addr = { 0 };
        addr.PhysicalAddress.QuadPart = (LONGLONG)address;
        return MmCopyMemory(buffer, addr, size, MM_COPY_MEMORY_PHYSICAL, read);
    }

    auto writephysaddress(PVOID address, PVOID buffer, SIZE_T size, SIZE_T* written) -> NTSTATUS
    {
        if (!address)
            return STATUS_UNSUCCESSFUL;

        PHYSICAL_ADDRESS addr = { 0 };
        addr.QuadPart = (LONGLONG)address;

        auto mapped_mem = MmMapIoSpaceEx(addr, size, PAGE_READWRITE);

        if (!mapped_mem)
            return STATUS_UNSUCCESSFUL;

        memcpy(mapped_mem, buffer, size);

        *written = size;
        MmUnmapIoSpace(mapped_mem, size);
        return STATUS_SUCCESS;
    }

    auto translateaddress(uint64_t processdirbase, uint64_t address) -> uint64_t
    {
        processdirbase &= ~0xf;

        uint64_t pageoffset = address & ~(~0ul << PAGE_OFFSET_SIZE);
        uint64_t pte = ((address >> 12) & (0x1ffll));
        uint64_t pt = ((address >> 21) & (0x1ffll));
        uint64_t pd = ((address >> 30) & (0x1ffll));
        uint64_t pdp = ((address >> 39) & (0x1ffll));

        SIZE_T readsize = 0;
        uint64_t pdpe = 0;
        readphysaddress((void*)(processdirbase + 8 * pdp), &pdpe, sizeof(pdpe), &readsize);
        if (~pdpe & 1)
            return 0;

        uint64_t pde = 0;
        readphysaddress((void*)((pdpe & mask) + 8 * pd), &pde, sizeof(pde), &readsize);
        if (~pde & 1)
            return 0;

        if (pde & 0x80)
            return (pde & (~0ull << 42 >> 12)) + (address & ~(~0ull << 30));

        uint64_t ptraddr = 0;
        readphysaddress((void*)((pde & mask) + 8 * pt), &ptraddr, sizeof(ptraddr), &readsize);
        if (~ptraddr & 1)
            return 0;

        if (ptraddr & 0x80)
            return (ptraddr & mask) + (address & ~(~0ull << 21));

        address = 0;
        readphysaddress((void*)((ptraddr & mask) + 8 * pte), &address, sizeof(address), &readsize);
        address &= mask;

        if (!address)
            return 0;

        return address + pageoffset;
    }

    auto readprocessmemory(PEPROCESS process, PVOID address, PVOID buffer, SIZE_T size, SIZE_T* read) -> NTSTATUS
    {
        auto process_dirbase = getprocessdirbase(process);

        SIZE_T curoffset = 0;
        while (size)
        {
            auto addr = translateaddress(process_dirbase, (ULONG64)address + curoffset);
            if (!addr) return STATUS_UNSUCCESSFUL;

            ULONG64 readsize = min(PAGE_SIZE - (addr & 0xFFF), size);
            SIZE_T readreturn = 0;
            auto readstatus = readphysaddress((void*)addr, (PVOID)((ULONG64)buffer + curoffset), readsize, &readreturn);
            size -= readreturn;
            curoffset += readreturn;
            if (readstatus != STATUS_SUCCESS) break;
            if (readreturn == 0) break;
        }

        *read = curoffset;
        return STATUS_SUCCESS;
    }

    auto writeprocessmemory(PEPROCESS process, PVOID address, PVOID buffer, SIZE_T size, SIZE_T* written) -> NTSTATUS
    {
        auto process_dirbase = getprocessdirbase(process);

        SIZE_T curoffset = 0;
        while (size)
        {
            auto addr = translateaddress(process_dirbase, (ULONG64)address + curoffset);
            if (!addr) return STATUS_UNSUCCESSFUL;

            ULONG64 writesize = min(PAGE_SIZE - (addr & 0xFFF), size);
            SIZE_T written = 0;
            auto writestatus = writephysaddress((void*)addr, (PVOID)((ULONG64)buffer + curoffset), writesize, &written);
            size -= written;
            curoffset += written;
            if (writestatus != STATUS_SUCCESS) break;
            if (written == 0) break;
        }

        *written = curoffset;
        return STATUS_SUCCESS;
    }
    PCHAR LowerStr(PCHAR str) {
        for (PCHAR s = str; *s; ++s) {
            *s = (CHAR)tolower(*s);
        }
        return str;
    }
    ULONG64 GetModuleBasex64(PEPROCESS proc, UNICODE_STRING module_name, BOOL get_size) {
        PPEB pPeb = (PPEB)PsGetProcessPeb(proc); // get Process PEB, function is unexported and undoc

        if (!pPeb) {
            return 0; // failed
        }

        KAPC_STATE state;

        KeStackAttachProcess(proc, &state);

        PPEB_LDR_DATA pLdr = (PPEB_LDR_DATA)pPeb->Ldr;

        if (!pLdr) {
            KeUnstackDetachProcess(&state);
            return 0; // failed
        }

        UNICODE_STRING name;

        // loop the linked list
        for (PLIST_ENTRY list = (PLIST_ENTRY)pLdr->InLoadOrderModuleList.Flink;
            list != &pLdr->InLoadOrderModuleList; list = (PLIST_ENTRY)list->Flink)
        {
            PLDR_DATA_TABLE_ENTRY pEntry =
                CONTAINING_RECORD(list, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);

            dbg("Module Name: %wZ\n", pEntry->BaseDllName);
            dbg("Module Base: %p\n", pEntry->DllBase);
            dbg("Module Size: %d\n", pEntry->SizeOfImage);

            if (RtlCompareUnicodeString(&pEntry->BaseDllName, &module_name, TRUE) ==
                0) {
                ULONG64 baseAddr = (ULONG64)pEntry->DllBase;
                ULONG64 moduleSize = (ULONG64)pEntry->SizeOfImage; // get the size of the module
                KeUnstackDetachProcess(&state);
                if (get_size) {
                    return moduleSize; // return the size of the module if get_size is TRUE
                }
                return baseAddr;
            }
        }

        KeUnstackDetachProcess(&state);

        return 0; // failed
    }
}