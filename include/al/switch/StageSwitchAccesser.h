/**
 * @file StageSwitchAccessor.h
 * @brief Access for a stage switch, which activates / deactives the event.
 */

#pragma once

#include "types.h"
#include "al/PlacementId.h"
#include "StageSwitchDirector.h"

enum StageSwitchFlags
{
    ENABLE_READ = 1,
    ENABLE_WRITE = 2
};

namespace al
{
    class StageSwitchListener;

    class StageSwitchAccesser
    {
    public:
        StageSwitchAccesser();

        void init(al::StageSwitchDirector *, char const *, al::PlacementId const &);
        al::StageSwitchDirector* getStageSwitchDirector() const;
        bool isValid() const;
        void onSwitch();
        void offSwitch();
        bool isOnSwitch() const;
        bool isEnableRead() const;
        bool isEnabledWrite() const;
        bool isEqualSwitch(al::StageSwitchAccesser const *) const;
        void addListener(al::StageSwitchListener *);

        al::StageSwitchDirector* mSwitchDir; // _0
        u64 _8;
        u64 _10;
        al::PlacementId* mPlacement; // _18
        u32 _20;
        StageSwitchFlags mFlags;
    };
};