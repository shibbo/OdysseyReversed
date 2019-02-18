/**
 * @file Application.cpp
 * @brief The main running class in the game.
 */

#include "al/util.h"
#include "al/shader/ShaderHolder.h"
#include "game/GameDataHolder.h"
#include "sead/color.h"
#include "system/Application.h"
#include "sead/framework.h"

sead::Heap* someHeap = (sead::Heap*)0x7102522A28;
char* sceneObjectName = (char*)0x71018AA876;

Application::Application() : IDisposer()
{
    this->_30 = 0;
    this->_38 = 0;
    this->mSystemKit = 0;
    this->_28 = 0;
}

void Application::init(s32 argc, char** argv)
{
    al::SystemKit* systemKit;

    // don't ask me why it does this because I don't know
    sead::Heap* curHeap = (sead::Heap*)1;

    if (sead::HeapMgr::sRootHeaps)
    {
        if (someHeap)
        {
            curHeap = sead::HeapMgr::sInstancePtr->setCurrentHeap_(someHeap);
        }
    }
    else
    {
        someHeap = 0;
    }
    
    systemKit = new al::SystemKit();
    this->mSystemKit = systemKit;
    systemKit->createMemorySystem(someHeap);

    if (curHeap != (sead::Heap*)1)
    {
        sead::HeapMgr::sInstancePtr->setCurrentHeap_(curHeap);
    }

    sead::Heap* stationedHeap = this->mSystemKit->mMemorySystem->mStationedHeap;
    sead::Heap* curStationedHeap = (sead::Heap*)1;

    if (stationedHeap)
    {
        curStationedHeap = sead::HeapMgr::sInstancePtr->setCurrentHeap_(stationedHeap);
    }

    sead::SafeStringBase<char> audioHeapStr;
    audioHeapStr.mCharPtr = "AudioHeap";
    
    sead::ExpHeap* audioHeap = sead::ExpHeap::create(0x12C00000, audioHeapStr, 0, 8, sead::Heap::HeapDirection::TAIL, 0);
    al::addNamedHeap(audioHeap, 0);

    sead::SafeStringBase<char> audioStationedRsrcHeap;
    audioStationedRsrcHeap.mCharPtr = "AudioStationedResourceHeap";

    sead::ExpHeap* audioStationedHeap = sead::ExpHeap::create(0x10E00000, audioStationedRsrcHeap, audioHeap, 8, sead::Heap::HeapDirection::TAIL, 0);
    al::addNamedHeap(audioStationedHeap, 0);

    sead::GameFrameworkNx::CreateArg createArg;
    createArg._1F = 0;
    createArg._20 = 0x80000;
    createArg._24 = 0x80000;
    createArg._28 = 0x1000;
    // this is some other color, looks like white
    createArg._C = *(sead::Color4f*)(0x71019ABDC8);
    createArg._3C = 0x40000;
    createArg._38 = 0x20000;
    createArg._40 = 0;
    createArg.presentInterval = 1;
    createArg._14 = 0x640;
    createArg._18 = 0x384;
    createArg._1E = 0;
    createArg._1C = 0;
    createArg._1D = 0;
    createArg._44 = 0x412C;
    createArg._34 = 0xFFFFFFFF;
    createArg._4 = sead::Color4f::cBlack;
    createArg._2C = 0x830000;
    createArg._30 = 0;

    al::GameFrameworkNx* framework = new al::GameFrameworkNx(createArg);
    this->_28 = framework;

    sead::Heap* curHeapMgrPtr = sead::HeapMgr::sInstancePtr->getCurrentHeap();
    s32 virtualDisplayWidth = (s32)al::getVirtualDisplayWidth();
    s32 virtualDisplayHeight = (s32)al::getVirtualDisplayHeight();

    sead::Vector2<f32> bounds;
    bounds.mX = virtualDisplayWidth;
    bounds.mY = virtualDisplayHeight;

    this->_28->initializeGraphicsSystem(curHeapMgrPtr, bounds);
    curHeapMgrPtr = sead::HeapMgr::sInstancePtr->getCurrentHeap();
    this->_28->initAgl(curHeapMgrPtr, virtualDisplayWidth, virtualDisplayHeight, 0x640, 0x384, 0x500, 0x2D0);

    this->_28->requestChangeUseGPU(false);

    al::initRegionAndLanguage();
    this->mSystemKit->createSaveDataSystem(0xA00400, *(u32*)0x7101F15898);

    GameDataHolder gameDataHolder;
    al::initSaveDirSync("NoUse.bin", 0xA00400, 1);
    al::readSaveDataSync("Common.bin", 0x400, 1);

    if (al::isSuccessSaveDataSequence() & 0x1)
    {
        gameDataHolder.readFromSaveDataBufferCommonFileOnlyLanguage();

        if (gameDataHolder.getLanguage())
        {
            char* language = gameDataHolder.getLanguage();

            if (!(al::isEqualString(language, sceneObjectName) & 0x1))
            {
                language = gameDataHolder.getLanguage();
                al::forceInitLanguage(language);
            }
        }
    }

    char* languageStr = al::getLanguageString();
    if (al::isEqualString(languageStr, "EUen") & 0x1)
    {
        al::forceInitLanguage("USen");
    }

    this->mSystemKit->createFileLoader(*(s32*)0x7101F1589C);
    this->mSystemKit->createResourceSystem(0, *(s32*)0x7101F158A0, 0x400000, 1);

    sead::SafeStringBase<char> stationedHeapStr;
    stationedHeapStr.mCharPtr = "StationedResourceHeap";

    sead::ExpHeap* stationedHeap = sead::ExpHeap::create(0x2EE00000, stationedHeapStr, this->mSystemKit->mMemorySystem->mStationedHeap, 8, sead::Heap::HeapDirection::TAIL, 0);
    al::addNamedHeap(stationedHeap, 0);

    sead::SafeStringBase<char> residentSysStr;
    residentSysStr.mCharPtr = "常駐[システム]";
    al::addResourceCategory(residentSysStr, 0x10, stationedHeap);

    sead::SafeStringBase<char> localResourceHeapStr;
    localResourceHeapStr.mCharPtr = "LocalizeResourceHeap";

    sead::FrameHeap* localizeResourceHeap = sead::FrameHeap::create(0x1400000, localResourceHeapStr, this->mSystemKit->mMemorySystem->mStationedHeap, 8, sead::Heap::HeapDirection::TAIL, 0);
    al::addNamedHeap(localizeResourceHeap, "LocalizeResourceHeap");

    sead::SafeStringBase<char> localResourceHeapStr_0;
    localResourceHeapStr_0.mCharPtr = "常駐[ローカライズ]";
    sead::Heap* localizeHeap = al::findNamedHeap("LocalizeResourceHeap");
    al::addResourceCategory(localResourceHeapStr_0, 0x50, localizeHeap);

    sead::SafeStringBase<char> permanentResourceStr;
    permanentResourceStr.mCharPtr = "常駐";
    al::addResourceCategory(permanentResourceStr, 0x200, stationedHeap);

    sead::SafeStringBase<char> residentShader;
    residentShader.mCharPtr = "常駐[シェーダー]";
    stationedHeap = al::findNamedHeap("StationedResourceHeap");
    al::addResourceCategory(residentShader, 0x40, stationedHeap);
    al::ShaderHolder::createInstance(stationedHeap);
    al::createCategoryResourceAll(residentShader);

    sead::Heap* audioStationedHeap = al::findNamedHeap("AudioStationedResourceHeap");
    sead::SafeStringBase<char> audioResidentStr;
    audioResidentStr.mCharPtr = "常駐[オーディオ]";
    al::addResourceCategory(audioResidentStr, 0x3A, audioStationedHeap);

    if (curHeap != (sead::Heap*)1)
    {
        sead::HeapMgr::sInstancePtr->setCurrentHeap_(curHeap);
    }
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
    sead::GameFrameworkNx::initialize(initArg);
}