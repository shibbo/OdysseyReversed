/**
 * @file print.h
 * @brief Print formatting class.
 */

#pragma once

#include "types.h"

namespace sead
{
    class PrintOutput;

    class PrintFormatter
    {
        public:

        template<typename T, typename T2>
        class OutImpl
        {
        public:   
            void out(T<T2> const &, char const *, sead::PrintOutput *);
        };

        PrintFormatter(char const *, sead::PrintOutput *);

        void flush();
        bool proceedToFormatMark_(char *);
        void flushWithLineBreak();
        void operator<<(char const *);
        void outputString_(char const *, sead::PrintOutput *, char const *, s32 strLength);
        void outputPtr_(char const *, sead::PrintOutput *, u64);

        template<typename T>
        void out(T const &, char const *, sead::PrintOutput *);

        char* mStr; // _0
        sead::PrintOutput* mPrintOutput; // _8
        s32 mStringLength; // _10
    };

    class PrintOutput
    {
    public:
        virtual ~PrintOutput();
        virtual void write(char const *, s32) = 0;

        void writeLineBreak();
        void operator<<(sead::PrintFormatter &);
    };

};