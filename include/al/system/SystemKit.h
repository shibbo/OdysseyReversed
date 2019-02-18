/**
 * @file MemorySystem.h
 * @brief Class for managing memory.
 */

#pragma once

#include "MemorySystem.h"
#include "sead/heap.h"
#include "types.h"

namespace al
{
    class SystemKit
    {
    public:
        SystemKit();

        void createMemorySystem(sead::Heap *);
        void createFileLoader(s32);
        void createResourceSystem(char const *, s32, s32, bool);
        void createSaveDataSystem(u32, s32);

        al::MemorySystem* mMemorySystem; // _0
        u64* _8; // al::FileLoader*
        u64* _10; // al::ResourceSystem*
        u64* _18; // al::SaveDataDirector*
    };
};