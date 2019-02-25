/**
 * @file CameraTicket.h
 * @brief Access classes for camera tickets.
 */

#pragma once

#include "al/PlacementId.h"
#include "types.h"

namespace al
{
    class CameraPoser;

    class CameraTicketId
    {
    public:
        CameraTicketId(al::PlacementId const *, char const *name);

        bool isEqual(al::CameraTicketId const &) const;
        static bool isEqual(al::CameraTicketId const &, al::CameraTicketId const &);
        bool isEqual(al::ByamlIter const &) const;
        u64 tryGetObjId() const;
        u64 getObjId() const;

        al::PlacementId* _0;
        char* mName; // _8
    };

    class CameraTicket
    {
    public:
        CameraTicket(al::CameraPoser *, al::CameraTicketId const *, s32 priority);

        void setPriority(s32);

        al::CameraPoser* mPoser; // _0
        al::CameraTicketId* mTicketId; // _8
        s32 mPriority; // _10
        bool mIsActive; // _14
    };
};