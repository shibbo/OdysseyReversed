/**
 * @file xml.h
 * @brief XML Elements / Documents
 */

#pragma once

#include "heap.h"
#include "string.h"
#include "tree.h"

namespace sead
{
    class XmlDocument
    {
    public:
        XmlDocument();
        virtual ~XmlDocument();

        void freeXmlElementAll();
        void resetEntity_(sead::Heap *);
        bool addEntity(sead::SafeStringBase<char> const &, sead::SafeStringBase<char> const &);
        bool eraseEntity(sead::SafeStringBase<char> const &);
        u32 expandEntityList(s32, sead::Heap *);
        //bool save(sead::WriteStream *, sead::Heap *, bool, sead::XmlElement *) const;

        u64 _8;
        u64 _10;
        u64 _18;
        u64 _20;
        u32 _28;
        u32 _2C; // padding?
        u64 _30;
        u64 _38;
        u32 _40;
        u32 _44; // padding?
        u64 _48;
        u64 _50;
        u32 _58;
        u32 _5C; // padding?
        u32 _60;

        static u64 sDefaultEntityNum;
    };

    class XmlElement
    {
    public:
        XmlElement();
        virtual ~XmlElement();

        sead::TreeNode* mRoot; // _8
    };
};