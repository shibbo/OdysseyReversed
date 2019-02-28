#pragma once

#include "al/shader/ShaderHolder.h"
#include "nn/g3d/ResModel.h"
#include "nn/gfx/api.h"
#include "nn/gfx/detail/pool.h"
#include "sead/heap.h"
#include "sead/matrix.h"

namespace al
{
    class ModelCtrl
    {
    public:
        ModelCtrl();
        ~ModelCtrl();

        void initialize(nn::g3d::ResModel *, s32, s32, sead::Heap *, al::ShaderHolder *);

        u64 _0;
        u64 _8;
        u64* _10; // al::GpuMemAllocator*
        u64* _18; // al::ModelShaderHolder*
        u32 _20;
        u32 _24;
        nn::gfx::detail::MemoryPoolImpl<nn::gfx::ApiVariation<nn::gfx::ApiType<4>,nn::gfx::ApiVersion<8>>> mMemoryPool; // _28
        u64 _148;
        u64 _150;
        u64 _158;
        u8 _160;
        u8 _161;
        u8 _162;
        u8 _163;
        u8 _164[0x368-0x164];
        u64* _368; // al::ModelLodCtrl*
        u64 _370;
        u64* _378; // al::DitherAnimator*
        u64* _380; // al::ModelMaterialCategory*
        u64* _388; // al::ModelDisplayListHolder*
        u64 _390;
        u64* _398; // al::ShadowDirector*
        u64* _3A0; // al::PrepassTriangleCulling*
        u64 _3A8;
        u64* _3B0; // al::Resource*
        u64* _3B8; // al::Resource*
        u8 _3C0[0x410-0x3C0];
        sead::Matrix34<f32>* _410;
        sead::Matrix34<f32>* _418;
        sead::Matrix44<f32>* _420;
        sead::Matrix44<f32>* _428;
        u64* _430; // al::ModelOcclusionQuery*
        u64 _338;
        u64 _340;
    };
};