#pragma once

#include "types.h"
#include "al/resource.h"
#include "sead/matrix.h"
#include "sead/vector.h"

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

        u64* _8; // maybe sead::SafeStringBase<char>*
        u64* _10; // al::ModelCtrl*
        al::ActorResource* mResource; // _18
        u64* _20; // al::AnimPlayerSkl*
        u64* _28; // al::AnimPlayerSimple*
        u64* _30; // al::AnimPlayerSimple*
        u64* _38; // al::AnimPlayerSimple*
        u64* _40; // al::AnimPlayerSimple*
        u64* _48; // al::AnimPlayerSimple*
        u64* _50; // al::AnimPlayerSimple*
        u64* _58;
        u8 _60;
        u8 _61;
        u8 _62;
        u8 _63;
        u32 _64;
    };
};