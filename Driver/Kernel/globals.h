#define WINDOWS_1803 17134
#define WINDOWS_1809 17763
#define WINDOWS_1903 18362
#define WINDOWS_1909 18363
#define WINDOWS_2004 19041
#define WINDOWS_20H2 19569
#define WINDOWS_21H2 20180
#define WINDOWS_22H2 22621
#define PAGE_OFFSET_SIZE 12

//request codes
#define DRIVER_READVM				0x80000001
#define CLIENT_BASE					0x80000002
#define WRITE					0x80000003
#define ENGINE_BASE					0x80000004
#define INPUT_BASE					0x80000005

static const uint64_t mask = (~0xfull << 8) & 0xfffffffffull;

struct _requests
{
	//rw
	uint32_t    src_pid;
	uint64_t    src_addr;
	uint64_t    dst_addr;
	size_t        size;

	//function requests
	int request_key;

	ULONG64 client_base;
};

namespace globals
{
	uintptr_t hook_pointer = 0;
	uintptr_t hook_address = 0;
}