#include "system/Application.h"

#include "sead/framework.h"

Application::Application()
{
    this->_30 = this->_38 = 0;
    this->mSystemKit = this->_28 = 0;
}

void ApplicationFunction::initialize(s32 argc, char **argv)
{
    sead::Framework::InitializeArg initArg;
    initArg._0 = 0xBFC00000;
    sead::GameFrameworkNX::initialize(initArg);
}