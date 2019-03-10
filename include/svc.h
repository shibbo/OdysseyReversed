/**
 * @file svc.h
 * @brief SVC declarations.
 */
#pragma once

#include "types.h"

struct MemoryInfo
{
    u64 baseAddress;
    u64 size;
    u32 type;
    u32 attribute;
    u32 permissions;
    u32 deviceReferenceCount;
    u32 ipcRefCount;
    u32 pad;
};

#ifdef __cplusplus
extern "C" {
#endif

Result svcSetHeapSize(void** address, u64 size); // 0x00
Result svcSetMemoryPermission(void* address, u64 size, u32 permissionFlag); // 0x01
Result svcSetMemoryAttribute(void* address, u64 size, u32 state_0, u32 state_1); // 0x02

Result svcQueryMemory(MemoryInfo* memInfo, u32* pageInfo, u64 address); // 0x06

u32 svcGetCurrentProcessorNumber(); // 0x10

u64 svcGetSystemTick(); // 0x1E

Result svcOutputDebugString(const char* str, u64 size); // 0x27

Result svcMapPhysicalMemory(void *address, u64 size); // 0x2C

Result svcSetUnsafeLimit(u64 size); // 0x4A

Result svcGetProcessList(u32* numPids, u64* pids, u32 maxProcessIDs); // 0x65

#ifdef __cplusplus
}
#endif