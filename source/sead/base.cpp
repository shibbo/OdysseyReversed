/**
 * @file base.h
 * @brief Base64 encoding / decoding.
 */

#include "sead/base.h"

namespace sead
{
    void Base64::encode(char* out, void const *inBytes, u64 length, bool useOtherSeed)
    {
        const char* seed;
        u64 v5, v6;
        char* v7;
        char* v8;
        s32 v9;

        seed = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

        if (useOtherSeed)
        {
            seed = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
        }

        v5 = 3 * (((u128)length * 0xAAAAAAAAAAAAAAABLL >> 63) >> 1);

        if (v5)
        {
            v6 = 0;

            do
            {
                v7 = (char*)inBytes + v6;
                v6 += 3;
                *out = seed[*v7 >> 2];
                out[1] = seed[((v7[1] >> 4) & 0xFFFFFFCF) | 16 * (*v7 & 3)];
                v8 = out + 4;
                out[2] = seed[((v7[2] >> 6) & 0xFFFFFFC3) | 4 * (v7[1] & 0xF)];
                out[3] = seed[v7[2] & 0x3F];
                out += 4;
            }
            while (v6 < v5);

            inBytes = (char*)inBytes + v6;
            out = v8;
        }

        v9 = (length - v5) & 0x3;

        if (v9 == 1)
        {
            *out = seed[(u64)*(u8*)inBytes >> 2];
            out[1] = seed[0x10 * (*(u8*)inBytes & 0x3)];
            out[2] = 0x3D;
        }
        else
        {
            if (v9 != 2)
            {
                return;
            }

            *out = seed[(u64)*(u8*)inBytes >> 2];
            out[1] = seed[(((u32)*((u8*)inBytes + 1) >> 4) & 0xFFFFFFCF) | 0x10 * (*(char*)inBytes & 3)];
            out[2] = seed[4 * ((*(u8*)inBytes + 1) & 0xF)];
        }

        out[3] = 0x3D;
    }
};