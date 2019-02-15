#include "al/util.h"
#include "al/camera/util.h"
#include "game/actor/shine/Shine.h"
#include "game/GameDataFunction.h"
#include "rs/util.h"

al::LiveActor* Shine::getCurrentModel()
{
    al::LiveActor* modelActor = this->_2E0;

    if (modelActor)
    {
        return this;
    }

    if (!this->mEmptyShineForDemoGetGrand)
    {
        modelActor = this->_2E0;
    }

    return modelActor;
}

void Shine::initAppearDemo(al::ActorInitInfo const &info)
{
    bool isWarpCamera, isReturnPrev, isUseZoom, v11;

    al::tryGetArg(&isWarpCamera, info, "IsUseWarpCamera");

    if (isWarpCamera)
    {
        this->mCameraTicket = al::initDemoProgramableCamera(this->mUseCamera, info, "AppearDemo", &this->_150, &this->_15C, 0);
        alCameraFunction::initPriorityDemo2(this->mCameraTicket);

        isReturnPrev = 0;
        bool res = al::tryGetArg(&isReturnPrev, info, "IsReturnPrevCameraParabolic");

        if (isReturnPrev && !((res ^ 1) & 0x1))
        {
            alCameraFunction::validateKeepPreSelfPoseNextCamera(this->mCameraTicket);
        }

        isUseZoom = 0;
        res = al::tryGetArg(&isUseZoom, info, "IsUseZoom");

        if (isUseZoom && !((res ^ 1) & 0x1))
        {
            al::RateParamF32* param = new al::RateParamF32();
            param->_0 = this->mUseCamera;
            param->_8 = this->mCameraTicket;
            param->_18 = 0;
            this->_370 = param;
        }
    }
}

void Shine::hideAllModel()
{
    al::LiveActor* actorToInvalidate;

    if (this->_2E0)
    {
        al::hideModelIfShow(this->_2E8);
        al::invalidateShadow(this->_2E8);
        al::hideModelIfShow(this->_2E0); 
        actorToInvalidate = this->_2E0;
    }
    else
    {
        al::hideModelIfShow(this);
        actorToInvalidate = this;
    }
    
    al::invalidateShadow(actorToInvalidate);
}

void Shine::invalidateKillSensor()
{
    if (!this->_294 && (this->_1A0 - 1) >= 2)
    {
        al::invalidateHitSensor(this, "Kill");
    }
}

void Shine::getDirect()
{
    this->showCurrentModel();
    al::invalidateClipping(this);
    // vtable + 0x18()
    if (this->mIsShopShine)
    {
        sead::Vector3<f32>* playerPos = rs::getPlayerPos(this);
        rs::requestStartDemoShineGet(this);

        if (this->_1A0 == 2)
        {
            GameDataFunction::recoveryPlayerMax(this);
        }

        rs::recoveryPlayerOxygen(this);

        // todo -- finish me
    }
}