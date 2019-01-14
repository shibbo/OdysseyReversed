#pragma once

#include "RootObject.h"
#include "types.h"

namespace nn
{
    namespace nex
    {
        class PseudoGlobalVariableRoot : public nn::nex::RootObject
        {
        public:
            PseudoGlobalVariableRoot();

            virtual ~PseudoGlobalVariableRoot();

            void ResetContextForAllVariables(u32);
            void AllocateExtraContextsForAllVariables(u64);
            void FreeExtraContextsForAllVariables();
            s64 GetNbOfExtraContexts();

            u64 _8;

            static s64 s_uiNbOfExtraContexts;
        };

        class PseudoGlobalVariableList : public nn::nex::RootObject
        {
        public:
            static u64* s_pVariableListHead;
        };

        template<typename T>
        class PseudoGlobalVariable : public nn::nex::RootObject { };
    };
};