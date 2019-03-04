/**
 * @file svc.h
 * @brief SVC declarations.
 */
#pragma once

#include "types.h"

extern "C" u64 svcGetSystemTick();
extern "C" Result svcOutputDebugString(const char *str, u64 size);
//extern "C" void NORETURN svcExitProcess();