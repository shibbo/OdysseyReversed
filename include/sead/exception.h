/**
 * @file exception.h
 * @brief Basic exception handling.
 */

#pragma once

#include "delegate.h"
#include "types.h"

namespace sead
{
    class AssertConfig
    {
    public:
        static void registerCallback(sead::DelegateEvent<char const *>::Slot &);
        static void unregisterCallback(sead::DelegateEvent<char const *>::Slot &);
        static void registerFinalCallback(sead::IDelegate1<char const *> *);
        static void execCallbacks(char const *);

        static sead::IDelegate1<char const *>* sFinalCallback;
    };

    class ExceptionHandler
    {
    public:

        class Information
        {
        public:
            Information();

            u64 _0;
            u64 _8;
            u64 _10;
            u64 _18;
        };

        static void initialize();
        static void registerCallback(sead::DelegateEvent<sead::ExceptionHandler::Information const &>::Slot &);
        static void unregisterCallback(sead::DelegateEvent<sead::ExceptionHandler::Information const &>::Slot &);
        // rest of these funcs involve nn::diag which is incomplete
    };
};