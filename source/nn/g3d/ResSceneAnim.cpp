#include "nn/g3d/ResSceneAnim.h"

namespace nn
{
    namespace g3d
    {
        s32 ResSceneAnim::Bind(BindFuncTable const &table)
        {
            u16 curFogIndex, fogAnimCount;
            u16 lightAnimCount = this->mLightAnimCount;
            u32 v7;
            s32 v14;
            u64 v15;

            if (lightAnimCount)
            {
                s32 curLightPos = 0;
                v7 = 0;

                do
                {
                    nn::g3d::ResLightAnim* lightAnim = this->mLightAnims + curLightPos;
                    v7 |= lightAnim->Bind(table);
                    curLightPos += 0x60;
                    --lightAnimCount;
                } 
                while (lightAnimCount);

                fogAnimCount = this->mFogAnimCount;
            }
            else
            {
                v7 = 0;
                fogAnimCount = lightAnimCount >> 16;
            }
            
            if (fogAnimCount)
            {
                ResFogAnim* fogAnims = this->mFogAnims;
                u64* v11 = (u64*)(fogAnims + 0x50 * curFogIndex);
                u8 v13 = *(v11 + 0x49);
                u8* v12 = (u8*)(v11 + 0x49);

                if (v13 == 0xFF)
                {
                    v15 = table._C;

                    if (v15 < 1)
                    {
                        v14 = 0x10000;
                    }
                    else
                    {
                        
                    }
                    
                }
            }
        }
    };
};