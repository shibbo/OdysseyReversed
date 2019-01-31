/**
 * @file execute.h
 * @brief Makes tables for execution states.
 */

#pragma once

#include "types.h"

namespace al
{
    class LiveActor;
	
    class ExecuteRequestInfo
    {
    public:
        ExecuteRequestInfo();

        u64 mRequestInfo; // _0
    };

    class ExecuteRequestTable
    {
    public:
        ExecuteRequestTable(u32 numEntries);

        u32 mNumEntries; // _0
        u32 mPad; // _4
        u64* mEntries; // _8
    };

    class ExecuteRequestKeeper
    {
    public:
        ExecuteRequestKeeper(u32 numEntries);

        void executeRequestActorMovementAllOn();
        void executeRequestActorMovementAllOff();
        void executeRequestActorDrawAllOn();
        void executeRequestActorDrawAllOff();
        void request(al::LiveActor *, s32 whichTable);

        al::ExecuteRequestTable* mMovementOnTable; // _0
        al::ExecuteRequestTable* mMovementOffTable; // _8
        al::ExecuteRequestTable* mDrawOnTable; // _10
        al::ExecuteRequestTable* mDrawOffTable; // _18
    };

    class ExecuteDirector
    {
    public:
        ExecuteDirector(s32);
        virtual ~ExecuteDirector();

        void createExecutorListTable();
        void execute(char const *);
        void executeList(char const *,char const *);
        void draw(char const *);
        void drawList(char const *,char const *);
        bool isActiveDraw(char const *) const;

        u32 _8;
        u64 _C;
        u64 _14;
        u32 _1C;
        u64 _20;
        u64 _28;
    };
};