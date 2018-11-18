#pragma once

#include "string.h"
#include "types.h"

namespace sead
{
    class CalendarTime
    {
        class Year
        {
            void setValue(u32 year);

            u32 mYear; // _0
        };

        class Month
        {
            Month(u32 month);

            void setValueOneOrigin(u32 month);
            void addSelf(u32 month);
            void subSelf(u32 month);
            u32 sub(sead::CalendarTime::Month) const;
            sead::SafeStringBase<char>* makeStringOneOrigin(u32 month);
            u32 makeFromValueOneOrigin(u32 month);

            u32 mMonth; // _0
        };

        class Day
        {
            void setValue(u32 day);

            u32 mDay; // _0
        };

        class Hour
        {
            void setValue(u32 hour);

            u32 mHour; // _0
        };

        class Minute
        {
            void setValue(u32 minute);

            u32 mMinute; // _0
        };

        class Second
        {
            void setValue(u32 second);

            u32 mSecond; // _0
        };

        class Date
        {
            Date(sead::CalendarTime::Year const &, sead::CalendarTime::Month const &, sead::CalendarTime::Day const &);
        
            sead::CalendarTime::Year mYear; // _0
            sead::CalendarTime::Month mMonth; // _4
            sead::CalendarTime::Day mDay; // _8
            u32 _C;
        };

        class Time
        {
            Time(sead::CalendarTime::Hour const &, sead::CalendarTime::Minute const &, sead::CalendarTime::Second const &);
        
            sead::CalendarTime::Hour mHour; // _0
            sead::CalendarTime::Minute mMinute; // _4
            sead::CalendarTime::Second mSecond; // _8
        };

        CalendarTime(sead::CalendarTime::Date const &, sead::CalendarTime::Time const &);
    };
};