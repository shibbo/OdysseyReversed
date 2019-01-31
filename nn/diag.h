/**
 * @file diag.h
 * @brief Module, logging, and symbol operations.
 */

#pragma once

#include "types.h"

namespace nn
{
    namespace diag
    {
        struct ModuleInfo;
        struct LogMetaData;

        namespace detail
        {
            // LOG
            void LogImpl(nn::diag::LogMetaData const &, char const *, ...);
            void AbortImpl(char const*, char const*, char const *, s32);
        };

        // MODULE / SYMBOL
        u32* GetSymbolName(char *name, u64 nameSize, u64 addr);
        u32 GetRequiredBufferSizeForGetAllModuleInfo();
        void GetAllModuleInfo(nn::diag::ModuleInfo **out, void *src, u64 numModules);
        u64 GetSymbolSize(u64 addr);
    };
};