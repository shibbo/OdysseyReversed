#pragma once

#include "types.h"

namespace sead
{
    class Endian
    {
        public:
        
        enum Types
        {
            BIG = 0,
            LITTLE = 1
        };
    };

    class Stream
    {
        public:

        Stream();
        virtual ~Stream();

        void skip(u32 howMany);
        void skip(u32, u32);
        void rewind();
        bool isEOF();

        u64 _8;
        u64* _10; // source, maybe
        sead::Endian::Types mEndianess; // _18
    };

    class ReadStream
    {

    };
};