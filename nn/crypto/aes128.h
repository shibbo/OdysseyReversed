#pragma once

#include "types.h"

namespace nn
{
    namespace crypto
    {
        void DecryptAes128Cbc(void *, u64, void const *, u64, void const *, u64, void const *, u64);
        void EncryptAes128Cbc(void *, u64, void const *, u64, void const *, u64, void const *, u64);
        void DecryptAes128Ccm(void *, u64, void *, u64, void const *, u64, void const *, u64, void const *, u64, void const *, u64, u64);
    };
};