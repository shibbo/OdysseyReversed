/**
 * @file exception.h
 * @brief Functions on printing out the exception handler.
 */

#pragma once

#include "nn/os.h"
#include "types.h"

namespace sead
{
    namespace nnsdk
    {
        void PrintExceptionType(nn::os::UserExceptionInfo *);
        void PrintThreadInformation(nn::os::UserExceptionInfo *, u64 *, u64 *);
        void PrintGeneralPurposeRegisters(nn::os::UserExceptionInfo *);
        void PrintSpecialRegisters(nn::os::UserExceptionInfo *);
        void PrintFloatingPointRegisters(nn::os::UserExceptionInfo *);
        void PrintAddressAndSymbol(u64);
        void PrintStackTrace(nn::os::UserExceptionInfo *);
        void PrintStackDump(nn::os::UserExceptionInfo *, u64, u64);
        void PrintModuleList();
        void PrintUserExceptionInfo(nn::os::UserExceptionInfo *);
    };
};