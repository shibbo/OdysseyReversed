#include "system/Application.h"

#include "sead/framework.h"

Application::Application() : IDisposer()
{
    this->_30 = 0;
    this->_38 = 0;
    this->mSystemKit = 0;
    this->_28 = 0;
}

void Application::run()
{
    sead::TaskClassID taskId;
    taskId.mTaskType = 2;

    sead::TaskBase::CreateArg taskBaseArg = sead::TaskBase::CreateArg::CreateArg(taskId);
    sead::Framework::RunArg runArg = sead::Framework::RunArg::RunArg();

    this->_28->run(this->mSystemKit->mMemorySystem->mStationedHeap, taskBaseArg, runArg);
}

void ApplicationFunction::initialize(s32 argc, char **argv)
{
    sead::Framework::InitializeArg initArg;
    initArg._0 = 0xBFC00000;
    sead::GameFrameworkNX::initialize(initArg);
}