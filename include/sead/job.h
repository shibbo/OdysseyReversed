/**
 * @file job.h
 * @brief Basic Job Querying.
 */

#pragma once

#include "core.h"
#include "event.h"

namespace sead
{
    typedef u32 SyncType;

    class JobQueue
    {
    public:
        JobQueue();

        virtual void begin();
        virtual void run(u32, u32 *, u64 *);
        virtual u32 getNumJobs() const;
        virtual bool isDone_();

        void setGranularity(sead::CoreId, u32);
        void setGranularity(u32);
        void setCoreMaskAndWaitType(sead::CoreIdMask, sead::SyncType);
        void runAll(u32 *);
        bool isAllParticipantThrough() const;
        void FINISH(sead::CoreId);
        void wait_AT_WORKER();
        void wait();

        sead::SyncType mSyncType; // _18
        u32 _1C;
        sead::CoreIdMask mCoreIDMask; // _20
        u8 _24[0x64-0x24];
        u32 _64;
        u32 _68;
        u32 _6C;
        u32 _70;
    };
};