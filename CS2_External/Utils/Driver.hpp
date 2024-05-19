#pragma once
#include <cstdint>
#include <cstdio>
#include <libloaderapi.h>
#include <string>
#include <vadefs.h>

class _driver
{
private:
	typedef INT64(*Nt_UserGetPointerProprietaryId)(uintptr_t);
	Nt_UserGetPointerProprietaryId NtUserGetPointerProprietaryId = nullptr;

	int _processid;
	ULONG64 _clientaddress;
	ULONG64 _engineaddress;


	//request codes
#define DRIVER_READVM				0x80000001
#define CLIENT_BASE					0x80000002
#define WRITE						0x80000003
#define ENGINE_BASE					0x80000004

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
		ULONG64 engine_base;
	};

	auto readvm(uint32_t src_pid, uint64_t src_addr, uint64_t dst_addr, size_t size) -> void
	{
		if (src_pid == 0 || src_addr == 0) return;

		_requests out = { src_pid, src_addr, dst_addr, size, DRIVER_READVM };
		NtUserGetPointerProprietaryId(reinterpret_cast<uintptr_t>(&out));
	}
	auto writevm(uint32_t src_pid, uint64_t src_addr, uint64_t dst_addr, size_t size) -> void
	{
		if (src_pid == 0 || dst_addr == 0) return;

		_requests out = { src_pid, src_addr, dst_addr, size, WRITE };
		NtUserGetPointerProprietaryId(reinterpret_cast<uintptr_t>(&out));
	}
public:
	auto initdriver(int processid) -> void
	{
		NtUserGetPointerProprietaryId = (Nt_UserGetPointerProprietaryId)GetProcAddress(LoadLibraryA("win32u.dll"), "NtUserGetPointerProprietaryId");
		if (NtUserGetPointerProprietaryId != 0)
		{
			printf("> NtUserGetPointerProprietaryId: %p\n", NtUserGetPointerProprietaryId);
			_processid = processid;
		}
	}



	void readsize(const uintptr_t address, const void* buffer, const size_t size)
	{
		readvm(_processid, address, uintptr_t(buffer), size);
	}


	std::string read_str(std::uintptr_t dst)
	{
		char buf[256];
		readsize(dst, &buf, sizeof(buf));
		return buf;
	}

	template <typename T>
	T readv(uintptr_t src, size_t size = sizeof(T))
	{
		T buffer;
		readvm(_processid, src, (uintptr_t)&buffer, size);
		return buffer;
	}

	template <typename T>
	T readteste(uintptr_t src, size_t size = sizeof(T))
	{
		T buffer;
		readvm(_processid, src, (uintptr_t)&buffer, size);
		return buffer;
	}

	template <typename T>
	void write(const uintptr_t address, const T& buffer)
	{
		writevm(_processid, address, (uintptr_t)&buffer, sizeof(T));
	}
	auto client_address() -> ULONG64
	{
		_requests out = { 0 };
		out.request_key = CLIENT_BASE;
		out.src_pid = _processid;
		NtUserGetPointerProprietaryId(reinterpret_cast<uintptr_t>(&out));
		_clientaddress = out.client_base;
		return out.client_base;
	}

	auto engine_address() -> ULONG64
	{
		_requests out = { 0 };
		out.request_key = ENGINE_BASE;
		out.src_pid = _processid;
		NtUserGetPointerProprietaryId(reinterpret_cast<uintptr_t>(&out));
		_engineaddress = out.client_base;
		return out.client_base;
	}
};

inline _driver driver;
