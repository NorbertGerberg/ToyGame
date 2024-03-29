/*=========================================
	Copyright 2024-2025 Norbert Gerberg
=========================================*/
#include "System.hpp"
#include <thread>
#include <Windows.h>
#include "Debug.hpp"

//#pragma comment(lib, "UxTheme.lib")
#pragma comment(lib, "wbemuuid.lib")

const uint eSystem::GetProcessorCount()
{
	return (const uint)std::thread::hardware_concurrency();
}

const uint64 eSystem::GetRAMsize()
{
	MEMORYSTATUSEX memSt;
	memSt.dwLength = sizeof(memSt);

	if (GlobalMemoryStatusEx(&memSt))
		return  memSt.ullTotalPhys / (1024 * 1024);
	TG_ASSERT(true);
}

const uint64 eSystem::GetAvailableRAMsize()
{
	MEMORYSTATUSEX memSt;
	memSt.dwLength = sizeof(memSt);

	if (GlobalMemoryStatusEx(&memSt))
		return  memSt.ullAvailPhys / (1024 * 1024);
	TG_ASSERT(true);
}

const uint64 eSystem::GetVirtualRAMsize()
{
	MEMORYSTATUSEX memSt;
	memSt.dwLength = sizeof(memSt);

	if (GlobalMemoryStatusEx(&memSt))
		return  memSt.ullTotalVirtual / (1024 * 1024);
	TG_ASSERT(true);
}

const uint64 eSystem::GetAvailableVirtualRAMsize()
{
	MEMORYSTATUSEX memSt;
	memSt.dwLength = sizeof(memSt);

	if (GlobalMemoryStatusEx(&memSt))
		return  memSt.ullAvailVirtual / (1024 * 1024);
	TG_ASSERT(true);
}

const uint64 eSystem::GetSpaceOnDisk()
{
	ULARGE_INTEGER freeBytesAvailable, totalNumberOfBytes, totalNumberOfFreeBytes;

	if (GetDiskFreeSpaceEx(nullptr, &freeBytesAvailable, &totalNumberOfBytes, &totalNumberOfFreeBytes))
		return totalNumberOfBytes.QuadPart / (1024 * 1024);
	TG_ASSERT(true);
}

const uint64 eSystem::GetAvailableSpaceOnDisk()
{
	ULARGE_INTEGER freeBytesAvailable, totalNumberOfBytes, totalNumberOfFreeBytes;

	if (GetDiskFreeSpaceEx(nullptr, &freeBytesAvailable, &totalNumberOfBytes, &totalNumberOfFreeBytes))
		return freeBytesAvailable.QuadPart / (1024 * 1024);
	TG_ASSERT(true);
}