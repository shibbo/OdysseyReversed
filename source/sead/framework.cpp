/**
 * @file framework.cpp
 * @brief Framework implementation.
 */

#include "sead/framework.h"

namespace sead
{
    Framework::CreateSystemTaskArg::CreateSystemTaskArg()
    {
        u32 v1 = 0x1000;
        this->_8 = 0;
        this->_10 = 0;
        this->_0 = 0;
        this->_18 = v1;
    }

    Framework::InitializeArg::InitializeArg()
    {
        u32 v1 = 0x3000000;
        this->_0 = v1;
        this->_8 = 0;
    }

    Framework::RunArg::RunArg()
    {
        u64 v1 = 0xFFFFFFFF00000000;
        this->_0 = v1;
    }

    Framework::Framework()
    {
        this->mNode.mBack = &this->mNode;
        this->mNode.mFront = &this->mNode;
        this->_8 = 0;
        this->_30 = 0;
        this->_40 = 0;
        this->_48 = 0;
        this->mTaskMgr = 0;
        this->_10 = 0;
        this->_18 = 0;
    }

    void Framework::createSystemTasks(sead::TaskBase *task, sead::Framework::CreateSystemTaskArg const &taskArg)
    {
        return;
    }

    void Framework::initRun_(sead::Heap *heap)
    {
        return;
    }

    void Framework::quitRun_(sead::Heap *heap)
    {
        return;
    }

    void Framework::runImpl_()
    {
        return;
    }
};