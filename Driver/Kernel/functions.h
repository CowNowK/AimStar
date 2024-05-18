#pragma once
#include <string>
auto readvm(_requests* in) -> bool
{
	PEPROCESS source_process = NULL;
	if (in->src_pid == 0) return STATUS_UNSUCCESSFUL;

	NTSTATUS status = PsLookupProcessByProcessId((HANDLE)in->src_pid, &source_process);
	if (status != STATUS_SUCCESS) return false;

	size_t memsize = 0;

	if (!NT_SUCCESS(utils::readprocessmemory(source_process, (void*)in->src_addr, (void*)in->dst_addr, in->size, &memsize)))
		return false;

	ObDereferenceObject(source_process);

	return true;
}

auto writevm(_requests* in) -> bool
{
	PEPROCESS source_process = NULL;
	if (in->src_pid == 0) return STATUS_UNSUCCESSFUL;

	NTSTATUS status = PsLookupProcessByProcessId((HANDLE)in->src_pid, &source_process);
	if (status != STATUS_SUCCESS) return false;

	size_t memsize = 0;

	if (!NT_SUCCESS(utils::writeprocessmemory(source_process, (void*)in->src_addr, (void*)in->dst_addr, in->size, &memsize)))
		return false;

	ObDereferenceObject(source_process);

	return true;
}

ULONG64 get_client_address(_requests* in)
{
	PEPROCESS source_process = NULL;
	if (in->src_pid == 0) return 0;
	NTSTATUS status = PsLookupProcessByProcessId((HANDLE)in->src_pid, &source_process);
	if (status != STATUS_SUCCESS) return 0;
	UNICODE_STRING moduleName;
	RtlInitUnicodeString(&moduleName, L"client.dll");
	ULONG64 base_address = utils::GetModuleBasex64(source_process, moduleName, false);
	return base_address;
}



auto requesthandler(_requests* pstruct) -> bool
{

	switch (pstruct->request_key)
	{

	case CLIENT_BASE:
	{
		ULONG64 base = get_client_address(pstruct);
		pstruct->client_base = base;
		return pstruct->client_base;
	}
	case DRIVER_READVM:
	{
		return readvm(pstruct);
	}
	case WRITE:
	{
		return writevm(pstruct);
	}

	}

	return true;
}

auto hooked_function(uintptr_t rcx) -> void
{
	_requests* in = (_requests*)rcx;
	requesthandler(in);
}
