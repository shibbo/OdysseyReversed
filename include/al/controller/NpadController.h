/**
 * @file NpadController.h
 * @brief Barebones class for a Switch gamepad.
 */

#pragma once

#include "sead/controller.h"

namespace al
{
    class NpadController : public sead::Controller
    {
    public:
        NpadController(sead::ControllerMgr *);
        virtual ~NpadController();

        virtual bool isConnected() const;
        virtual void calcImpl_();

        bool isValidNpadId() const;
        u32 getNpadId() const;
        void setAnyControllerMode();
        void setIndexControllerMode(s32);
        u64* getVibrationDeviceHandle(s32) const;

        u32 mMode; // _178
        u32 mPadID; // _17C
        u32 _180;
    };
};