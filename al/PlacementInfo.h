#pragma once

#include "types.h"
#include "al/byaml/ByamlIter.h"

namespace al
{
    class PlacementInfo : public al::ByamlIter
    {
    public:
        PlacementInfo();

        void set(al::ByamlIter const &, al::ByamlIter const &);

        u8* _0;
        u8* _8;
        u8* _10;
        u8* _18;
    };
};