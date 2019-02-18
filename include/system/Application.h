/**
 * @file Application.h
 * @brief The main running class in the game.
 */

#pragma once

#include "al/system/GameFrameworkNx.h"
#include "al/system/SystemKit.h"
#include "sead/heap.h"

class RootTask;

class Application : public sead::IDisposer
{
public:

    class SingletonDisposer_ : public sead::IDisposer
    {
    public:
        virtual ~SingletonDisposer_();
    };

    Application();

    static Application* createInstance(sead::Heap *);
    static void deleteInstance();
    void init(s32, char **);
    void run();
    RootTask* getRootTask() const;

    al::SystemKit* mSystemKit; // _20
    al::GameFrameworkNx* _28; // _28
    u64* _30;
    u64* _38; // al::AccountHolder

    static Application* sInstance;
};

class ApplicationFunction
{
public:
    static void initialize(s32, char**);
};