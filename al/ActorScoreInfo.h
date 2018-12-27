#pragma once

namespace al
{
    class ByamlIter;

    class ActorScoreInfo
    {
    public:
        ActorScoreInfo();
        
        void init(al::ByamlIter const &);

        char** mFactorName; // _0
        char** mCategoryName; // _8
    };
};