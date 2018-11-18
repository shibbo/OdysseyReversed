#pragma once

#include "heap.h"

namespace sead
{
    class system
    {
        public:
        static void NewImpl(sead::Heap *, u64, s32, bool);
        static void DeleteImpl(void *src);
        static bool Halt();
        static bool HaltWithDetail(char const *, s32, char const *, ...);
        static bool DebugBreak();
        static void Print(char const *, ...);
        static void PrintString(char const *, s32);
    };
};