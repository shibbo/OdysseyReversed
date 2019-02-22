/**
 * @file KCollisionServer.h
 * @brief Serves as a "server" (storage container) for collision attributes from a BYAML.
 */

#pragma once

#include "types.h"
#include "al/byaml/ByamlIter.h"

namespace al
{
    class KCollisionServer
    {
    public:
        KCollisionServer();

        void initKCollisionServer(void *, void const *byamlSrc);
        void setData(void *kclSrc);

        u64 _0;
        u64 _8;
        void* mKCLSource; // _10
        al::ByamlIter* mColIterator; // _18
        u8 _20[0x50-0x20];
    };
};