#include "sead/random.h"

#include "nn/os.h"
#include "operator.h"

namespace sead
{
    void Random::init()
    {
        nn::os::Tick systemTick = nn::os::GetSystemTick();

        this->mSeed1 = 0x6C078965 * (systemTick ^ (systemTick >> 30)) + 1;
        this->mSeed2 = 0x6C078965 * (this->mSeed1 ^ (this->mSeed1 >> 30)) + 2;
        this->mSeed3 = 0x6C078965 * (this->mSeed2 ^ (this->mSeed2 >> 30)) + 3;
        this->mSeed4 = 0x6C078965 * (this->mSeed3 ^ (this->mSeed3 >> 30)) + 4;
    }

    void Random::init(u32 seed)
    {
        this->mSeed1 = 0x6C078965 * (seed ^ (seed >> 30)) + 1;
        this->mSeed2 = 0x6C078965 * (this->mSeed1 ^ (this->mSeed1 >> 30)) + 2;
        this->mSeed3 = 0x6C078965 * (this->mSeed2 ^ (this->mSeed2 >> 30)) + 3;
        this->mSeed4 = 0x6C078965 * (this->mSeed3 ^ (this->mSeed3 >> 30)) + 4;
    }

    void Random::init(u32 seed1, u32 seed2, u32 seed3, u32 seed4)
    {
        if (seed2 | seed1 | seed3 | seed4)
        {
            this->mSeed1 = seed1;
        }
        else
        {
            this->mSeed1 = 1;
        }

        if (seed2 | seed1 | seed3 | seed4)
        {
            this->mSeed2 = seed2;
        }
        else
        {
            this->mSeed2 = 0x6C078967;
        }

        if (seed2 | seed1 | seed3 | seed4)
        {
            this->mSeed3 = seed3;
        }
        else
        {
            this->mSeed3 = 0x714ACB41;
        }

        if (seed2 | seed1 | seed3 | seed4)
        {
            this->mSeed4 = seed4;
        }
        else
        {
            this->mSeed4 = 0x48077044;
        }
    }

    u32 Random::getU32()
    {
        u32 v1 = this->mSeed1 ^ (this->mSeed1 << 11);
        this->mSeed1 = this->mSeed2;
        u32 ogSeed4 = this->mSeed4;
        u32 val = v1 ^ (v1 >> 8) ^ ogSeed4 ^ (ogSeed4 >> 19);
        this->mSeed3 = ogSeed4;
        this->mSeed4 = val;
        
        return val;
    }

    u64 Random::getU64()
    {
        u32 ogSeed2 = this->mSeed2;
        u32 v2 = this->mSeed1 ^ (this->mSeed1 << 11);
        u32 ogSeed4 = this->mSeed4;
        this->mSeed1 = this->mSeed3;
        this->mSeed2 = ogSeed4;
        u32 v4 = v2 ^ (v2 >> 8) ^ ogSeed4;
        u32 seed3 = v4 ^ (ogSeed4 >> 19);
        u32 val = ogSeed2 ^ (ogSeed2 << 11) ^ ((ogSeed2 ^ (ogSeed2 << 11)) >> 8) ^ seed3 ^ (v4 >> 19);
        this->mSeed3 = seed3;
        this->mSeed4 = val;
        
        return val | (seed3 << 31);
    }

    void Random::getContext(u32* seed1, u32* seed2, u32* seed3, u32* seed4) const
    {
        *seed1 = this->mSeed1;
        *seed2 = this->mSeed2;
        *seed3 = this->mSeed3;
        *seed4 = this->mSeed4;
    }

    GlobalRandom::SingletonDisposer_::~SingletonDisposer_()
    {
        GlobalRandom::sInstance = 0;
        GlobalRandom::SingletonDisposer_::sStaticDisposer = 0;
    }

    /*GlobalRandom* GlobalRandom::createInstance(sead::Heap *heap)
    {
        GlobalRandom* instance;
        GlobalRandom* gr;

        instance = GlobalRandom::sInstance;

        if (GlobalRandom::sInstance)
        {
            void* random = operator new[](sizeof(GlobalRandom), heap, 4);
            
        }
    }*/
};