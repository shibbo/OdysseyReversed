/**
 * @file ByamlWriter.h
 * @brief Writer stream for BYAML files.
 */

#pragma once

#include "sead/heap.h"
#include "types.h"

namespace al
{
    class ByamlWriterBigDataList;
    class ByamlWriterStringTable;

    class ByamlWriter
    {
    public:
        ByamlWriter(sead::Heap *, bool);

        virtual ~ByamlWriter();

        void addBool(bool);
        u64* getArrayCurrentContainer();
        void addInt(s32);
        void addUInt(u32);
        void addFloat(f32);
        void addInt64(s64);
        void addUInt64(u64);
        void addDouble(f64);
        void addString(char const *);
        void addNull();
        // todo -- finish me

        sead::Heap* mHeap; // _8
        al::ByamlWriterStringTable* _10;
        al::ByamlWriterStringTable* _18;
        u64 _20;
        u64 _28;
        u64 _30;
        u64 _38;
        al::ByamlWriterBigDataList* _40;
        u32 _48;
        u32 _4C;
        u8 _50;
    };
};