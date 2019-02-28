/**
 * @file ModelKeeper.h
 * @brief Keeper for all model data.
 */

#pragma once

#include "al/anim/AnimPlayerMat.h"
#include "al/model/ModelCtrl.h"
#include "al/resource.h"
#include "sead/matrix.h"
#include "sead/vector.h"
#include "types.h"

namespace al
{
    class ModelKeeper
    {
    public:
        ModelKeeper();

        virtual ~ModelKeeper();

        void initResource(al::ActorResource const *);
        void createMatAnimForProgram(s32);
        u64* getAnimResource() const;
        u64* getModelResource() const;
        void setDisplayRootJointMtxPtr(sead::Matrix34<f32> const *);
        void setModelLodCtrl(u64 *); // al::ModelCtrl*

        void show();
        void hide();
        void update();
        void updateLast();
        void calc(sead::Matrix34<f32> const &, sead::Vector3<f32> const &);
        sead::Matrix34<f32>* getBaseMtx() const;
        sead::Matrix34<f32>* getWorldMtxPtrByIndex(s32) const;

        char* mResourceName; // _8
        al::ModelCtrl* mModelControl; // _10
        al::ActorResource* mResource; // _18
        u64* _20; // al::AnimPlayerSkl*
        al::AnimPlayerMat* _28;
        al::AnimPlayerMat* _30;
        al::AnimPlayerMat* _38;
        al::AnimPlayerMat* _40;
        u64* _48; // al::AnimPlayerVis*
        u64* _50; // al::AnimPlayerVis*
        u64* _58;
        u8 _60;
        u8 _61;
        u8 _62;
        u8 _63;
        u32 _64;
    };
};