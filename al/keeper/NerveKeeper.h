/**
 * @file NerveKeeper.h
 * @brief Keeper for an actors' "nerves", or collider points.
 */

#pragma once

#include "types.h"

namespace al
{
    class Nerve;
    class IUseNerve;

    class NerveKeeper
    {
    public:
        NerveKeeper(al::IUseNerve *, al::Nerve const *, s32);

        void update();
        void tryChangeNerve();
        void setNerve(al::Nerve *);
        al::Nerve* getCurrentNerve() const;
        void initNerveAction(u64 *);

        u64* _0; // al::NerveStateCtrl*
        u64 _8;
        al::Nerve* _10;
        u32 _18;
        u32 _1C;
        u64* _20; // al::NerveStateCtrl*
        u64* _28; // al::NerveActionCtrl*
    };
};