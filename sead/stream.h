/**
 * @file stream.h
 * @brief Binary/Text I/O Streaming
 */

#pragma once

#include "types.h"

namespace sead
{
    class StreamFormat;
    class StreamSrc;

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
        enum Modes
        {
            BINARY = 0,
            TEXT = 1
        };

        Stream();
        Stream(sead::StreamSrc *, sead::Stream::Modes);
        Stream(sead::StreamSrc *, sead::StreamFormat *);
        virtual ~Stream();

        void setMode(sead::Stream::Modes);
        void setUserFormat(sead::StreamFormat *);
        void setBinaryEndian(sead::Endian::Types);
        void skip(u32 howMany);
        void skip(u32, u32);
        void rewind();
        bool isEOF();

        sead::StreamFormat* mStreamFormat; // _8
        sead::StreamSrc* mSrc; // _10
        sead::Endian::Types mEndianess; // _18
    };

    class ReadStream { };

    class WriteStream { };
};