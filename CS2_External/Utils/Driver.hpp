#pragma once
#include <cstdint>
#include <cstdio>
#include <libloaderapi.h>
#include <string>
#include <vadefs.h>
constexpr ULONG ioctl_call_driver = CTL_CODE(FILE_DEVICE_UNKNOWN, 0x775, METHOD_BUFFERED, FILE_SPECIAL_ACCESS);

class _driver
{
private:
	HANDLE _driver_handle;
	int _processid;
	ULONG64 _clientaddress;
	ULONG64 _engineaddress;


	//request codes
#define DRIVER_READVM				0x80000001
#define CLIENT_BASE					0x80000002
#define WRITE						0x80000003
#define ENGINE_BASE					0x80000004
#define INPUT_BASE					0x80000005

	struct _requests
	{
		//rw
		uint32_t    src_pid;
		uint64_t    src_addr;
		uint64_t    dst_addr;
		size_t        size;

		//function requests
		DWORD64 request_key;

		ULONG64 client_base;
		ULONG64 engine_base;
	};

	auto readvm(uint32_t src_pid, uint64_t src_addr, uint64_t dst_addr, size_t size) -> void
	{
		if (src_pid == 0 || src_addr == 0) return;

		_requests out = { src_pid, src_addr, dst_addr, size, DRIVER_READVM };
		DeviceIoControl(_driver_handle, ioctl_call_driver, &out, sizeof(out), nullptr, 0, nullptr, nullptr);
	}
	auto writevm(uint32_t src_pid, uint64_t src_addr, uint64_t dst_addr, size_t size) -> void
	{
		if (src_pid == 0 || dst_addr == 0) return;

		_requests out = { src_pid, src_addr, dst_addr, size, WRITE };
		DeviceIoControl(_driver_handle, ioctl_call_driver, &out, sizeof(out), nullptr, 0, nullptr, nullptr);
	}
public:
	auto initdriver(int processid) -> void
	{
		_driver_handle = CreateFileA("\\\\.\\AimStarDriver", GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr); //get a handle to our driver
		if (_driver_handle != INVALID_HANDLE_VALUE)
		{
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
	template <typename T>
	void write(const uintptr_t address, const T& buffer, int Size)
	{
		writevm(_processid, address, (uintptr_t)&buffer, Size);
	}
	auto client_address() -> ULONG64
	{
		_requests out = { 0 };
		out.request_key = CLIENT_BASE;
		out.src_pid = _processid;
		DeviceIoControl(_driver_handle, ioctl_call_driver, &out, sizeof(out), &out, sizeof(out), nullptr, nullptr);
		_clientaddress = out.client_base;
		return out.client_base;
	}

	auto engine_address() -> ULONG64
	{
		_requests out = { 0 };
		out.request_key = ENGINE_BASE;
		out.src_pid = _processid;
		DeviceIoControl(_driver_handle, ioctl_call_driver, &out, sizeof(out), &out, sizeof(out), nullptr, nullptr);
		_engineaddress = out.client_base;
		return out.client_base;
	}

	auto input_address() -> ULONG64
	{
		_requests out = { 0 };
		out.request_key = INPUT_BASE;
		out.src_pid = _processid;
		DeviceIoControl(_driver_handle, ioctl_call_driver, &out, sizeof(out), &out, sizeof(out), nullptr, nullptr);
		_engineaddress = out.client_base;
		return out.client_base;
	}
};

inline _driver driver;
