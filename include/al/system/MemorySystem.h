/**
 * @file MemorySystem.h
 * @brief Main memory management class in the game.
 */

#pragma once

#include "sead/heap.h"

namespace al
{
    class MemorySystem
    {
    public:
        MemorySystem(sead::Heap *);

        void createSequenceHeap();
        void freeAllSequenceHeap();
        void printSequenceHeap();
        void createSceneHeap(char const *, bool);
        void createSceneResourceHeap(char const *, bool);
        void destroySceneHeap();
        void destroySceneResourceHeap();
        void createCourseSelectHeap();
        void destroyCourseSelectHeap();
        void createWorldResourceHeap();
        void destroyWorldResourceHeap();
        void freeAllPlayerHeap();
        sead::Heap* tryFindNamedHeap(char const *) const;
        sead::Heap* findNamedHeap(char const *) const;
        void addNamedHeap(sead::Heap *, char const *);
        void removeNamedHeap(char const *);

        sead::ExpHeap* mStationedHeap; // _0
        sead::FrameHeap* mSequenceHeap; // _8
        u64 _10;
        sead::FrameHeap* mSceneHeap; // _18
        u64 _20;
        sead::FrameHeap* mCourseSelectHeap; // _28
        sead::FrameHeap* mCourseSelectHeapScene; // _30
        sead::FrameHeap* mWorldHeapResource; // _38
    };
};