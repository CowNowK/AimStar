#include "imports.h"
#include "functions.h"

//https://github.com/beans42/kernel-read-write-using-ioctl
auto real_main(PDRIVER_OBJECT driver_obj, PUNICODE_STRING registery_path) -> NTSTATUS
{
	UNREFERENCED_PARAMETER(registery_path);

	UNICODE_STRING dev_name, sym_link;
	PDEVICE_OBJECT dev_obj;

	RtlInitUnicodeString(&dev_name, L"\\Device\\AimStarDriver"); //die lit
	auto status = IoCreateDevice(driver_obj, 0, &dev_name, FILE_DEVICE_UNKNOWN, FILE_DEVICE_SECURE_OPEN, FALSE, &dev_obj);
	if (status != STATUS_SUCCESS) return status;

	RtlInitUnicodeString(&sym_link, L"\\DosDevices\\AimStarDriver");
	status = IoCreateSymbolicLink(&sym_link, &dev_name);
	if (status != STATUS_SUCCESS) return status;

	SetFlag(dev_obj->Flags, DO_BUFFERED_IO); //set DO_BUFFERED_IO bit to 1

	//then set supported functions to appropriate handlers
	driver_obj->MajorFunction[IRP_MJ_CREATE] = default_dispatch; //link our io create function
	driver_obj->MajorFunction[IRP_MJ_CLOSE] = default_dispatch; //link our io close function
	driver_obj->MajorFunction[IRP_MJ_DEVICE_CONTROL] = ioctl_dispatch; //link our control code handler
	driver_obj->DriverUnload = NULL; //add later

	ClearFlag(dev_obj->Flags, DO_DEVICE_INITIALIZING); //set DO_DEVICE_INITIALIZING bit to 0 (we are done initializing)
	dbg("[AimStar] DRIVER LOADED SUCCEFULLY");
	return status;
}


auto driver_entry() -> const NTSTATUS
{
	UNICODE_STRING  drv_name;
	RtlInitUnicodeString(&drv_name, L"\\Driver\\AimStarDriver");
	return IoCreateDriver(&drv_name, real_main); //so it's kdmapper-able
}