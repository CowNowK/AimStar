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

ULONG64 get_engine_address(_requests* in)
{
	PEPROCESS source_process = NULL;
	if (in->src_pid == 0) return 0;
	NTSTATUS status = PsLookupProcessByProcessId((HANDLE)in->src_pid, &source_process);
	if (status != STATUS_SUCCESS) return 0;
	UNICODE_STRING moduleName;
	RtlInitUnicodeString(&moduleName, L"engine2.dll");
	ULONG64 base_address = utils::GetModuleBasex64(source_process, moduleName, false);
	return base_address;
}

ULONG64 get_input_address(_requests* in)
{
	PEPROCESS source_process = NULL;
	if (in->src_pid == 0) return 0;
	NTSTATUS status = PsLookupProcessByProcessId((HANDLE)in->src_pid, &source_process);
	if (status != STATUS_SUCCESS) return 0;
	UNICODE_STRING moduleName;
	RtlInitUnicodeString(&moduleName, L"inputsystem.dll");
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
	case ENGINE_BASE:
	{
		ULONG64 base = get_engine_address(pstruct);
		pstruct->client_base = base;
		return pstruct->client_base;
	}
	case INPUT_BASE:
	{
		ULONG64 base = get_input_address(pstruct);
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

auto default_dispatch(PDEVICE_OBJECT device_obj, PIRP irp) -> NTSTATUS
{
	irp->IoStatus.Status = STATUS_SUCCESS;
	irp->IoStatus.Information = 0;
	IoCompleteRequest(irp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

auto ioctl_dispatch(PDEVICE_OBJECT device_obj, PIRP irp	) -> NTSTATUS
{
	irp->IoStatus.Status = STATUS_SUCCESS;
	irp->IoStatus.Information = 0;
	auto stack = IoGetCurrentIrpStackLocation(irp);
	auto buffer = (_requests*)irp->AssociatedIrp.SystemBuffer;
	auto length = stack->Parameters.DeviceIoControl.InputBufferLength;
	auto ctl_code = stack->Parameters.DeviceIoControl.IoControlCode;
	if (length >= sizeof(_requests))
	{
		if (ctl_code == ioctl_call_driver && requesthandler(buffer))
		{
			irp->IoStatus.Information = sizeof(_requests);
			irp->IoStatus.Status = STATUS_SUCCESS;
		}
		else
		{
			irp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
		}
	}
	else
	{
		irp->IoStatus.Status = STATUS_BUFFER_TOO_SMALL;
	}
	IoCompleteRequest(irp, IO_NO_INCREMENT);
	return irp->IoStatus.Status;
}