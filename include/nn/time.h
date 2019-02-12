/**
 * @file time.h
 * @brief Time implementation.
 */

#pragma once

#include "types.h"

namespace nn
{
    namespace time
    {
        Result Initialize();
        bool IsInitialzed();

        struct CalendarTime
        {
            s16 year;
            s8 month;
            s8 day;
            s8 hour;
            s8 minute;
            s8 second;
        };
        
        enum DayOfTheWeek
        {
            Sunday,
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday
        };

        struct CalendarAdditionalInfo
        {
            nn::time::DayOfTheWeek dayOfTheWeek;
            s32 dayofYear;
            nn::time::TimeZone timeZone;
        };

        struct PosixTime
        {
            u64 time;
        };

        class StandardUserSystemClock
        {
        public:
            static Result GetCurrentTime(nn::time::PosixTime *);
        };

        struct TimeZone
        {
            char standardTimeName[0x8];
            bool _9; // daylight savings or something?
            s32 utcOffset; // in seconds
        };
        
        struct TimeZoneRule; // shrug

        Result ToCalendarTime(nn::time::CalendarTime *, nn::time::CalendarAdditionalInfo *, nn::time::PosixTime const &, nn::time::TimeZoneRule const &);
    };
};