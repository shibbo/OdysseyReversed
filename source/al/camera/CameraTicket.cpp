/**
 * @file CameraTicket.cpp
 * @brief Access classes for camera tickets.
 */

#include "al/camera/CameraTicket.h"
#include "al/util.h"

namespace al
{
    CameraTicketId::CameraTicketId(al::PlacementId const *id, char const *name)
    {
        this->_0 = (al::PlacementId*)id;
        this->mName = (char*)name;
    }

    bool CameraTicketId::isEqual(al::CameraTicketId const &ticket) const
    {
        bool res;

        if (!this->_0)
        {
            if (!ticket._0)
            {
                return al::isEqualString(this->mName, ticket.mName);
            }

            return false;
        }

        if (!ticket._0 || !(this->_0->isEqual(*ticket._0) & 0x1))
        {
            return false;
        }

        res = (*this->mName | *ticket.mName) == 0;
        
        if (this->mName && ticket.mName)
        {
            res = al::isEqualString(this->mName, ticket.mName);
        }

        return res;
    }

    bool CameraTicketId::isEqual(al::CameraTicketId const &ticket1, al::CameraTicketId const &ticket2)
    {
        bool res;

        if (!ticket1._0)
        {
            if (!ticket2._0)
            {
                return al::isEqualString(ticket1.mName, ticket2.mName);
            }

            return false;
        }

        if (!ticket2._0 || !(ticket1._0->isEqual(*ticket2._0) & 0x1))
        {
            return false;
        }

        res = (*ticket1.mName | *ticket2.mName) == 0;
        
        if (ticket1.mName && ticket2.mName)
        {
            res = al::isEqualString(ticket1.mName, ticket2.mName);
        }

        return res;
    }

    CameraTicket::CameraTicket(al::CameraPoser *poser, al::CameraTicketId const *cameraTicket, s32 priority)
    {
        this->mPoser = poser;
        this->mTicketId = (al::CameraTicketId*)cameraTicket;
        this->mPriority = priority;
        this->mIsActive = false;
    }

    void CameraTicket::setPriority(s32 priority)
    {
        this->mPriority = priority;
    }
};