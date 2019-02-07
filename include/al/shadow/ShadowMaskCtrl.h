/**
 * @file ShadowMaskControl.h
 * @brief Control for shadow masks.
 */

#include "al/byaml/ByamlIter.h"
#include "al/LiveActor.h"
#include "sead/color.h"
#include "sead/vector.h"
#include "types.h"

namespace al
{
    class ShadowMaskCtrl
    {
    public:
        class ShadowMaskBaseInfo
        {
        public:
            void readIter(al::ByamlIter const &maskIter);
            void setPtr();

            char* mName; // _0
            char* mMaskType; // _8
            char* mActorJointName; // _10
            sead::Vector3<f32> mOffset; // _18
            sead::Color4f mColor; // _24
            bool mApplyShadowIntensityUser; // _34
            u8 mShadowIntensityUser; // _35
            bool mIgnoreHide; // _36
            bool mFollowHostScale; // _37
            char* mDrawCategory; // _38
            bool mShadowFixed; // _40
            u8 _41[0x48-0x41]; // probably padding from that boolean above
            char* mSetHeightTargetName; // _48
        };

        ShadowMaskCtrl(bool);

        void initShadowMaskNum(s32 bufferAmount);

        void show();
        void init(al::LiveActor *, s32 bufferAmount);
        void initAfterPlacement();
        void hide();
        void validate();
        void invalidate();
        bool isHide() const;

        // pretty sure the first member is a ptr array of shadow masks
        u8 _0[0x40];
        al::LiveActor* mActor; // _40
    };
};