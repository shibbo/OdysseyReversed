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
        void setData(void *);

        al::ByamlIter* mColIterator; // _18
    };
};