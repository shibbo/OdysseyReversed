/**
 * @file list.h
 * @brief List Node Tree Implementation.
 */

#pragma once

#include "types.h"

namespace sead
{
    class Random;

    class ListNode
    {
    public:
        void insertBack_(sead::ListNode *);
        void insertFront_(sead::ListNode *);
        void erase_();

        sead::ListNode* mFront; // _0
        sead::ListNode* mBack; // _8
    };

    class ListImpl
    {
    public:
        sead::ListNode* popBack();
        sead::ListNode* popFront();
        sead::ListNode* nth(s32 where) const;
        s32 indexOf(sead::ListNode const *) const;
        void clear();
        void swap(sead::ListNode *, sead::ListNode *);
        void moveAfter(sead::ListNode *, sead::ListNode *);
        void moveBefore(sead::ListNode *, sead::ListNode *);
        sead::ListNode* find(void const *, s32, s32 (*)(void const *, void const *)) const;
        void reverse();
        void shuffle(sead::Random *);
        void sort(s32, s32 (*)(void const *, void const *));
        void mergeSort(s32, s32 (*)(void const *, void const *));
        void mergeSortImpl(sead::ListNode *, sead::ListNode *, s32, s32, s32 (*)(void const *, void const *));
        void uniq(s32, s32 (*)(void const *, void const *));
        s32 checkLinks() const;

        sead::ListNode* mFront; // _0
        sead::ListNode* mBack; // _8
        s32 mNumNodes; // _10
    };
};