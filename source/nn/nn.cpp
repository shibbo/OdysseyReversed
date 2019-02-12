/**
 * @file nn.cpp
 * @brief Barebones NN functions, such as init and nnMain.
 */

#include "nn/init.h"
#include "nn/oe.h"
#include "nn/os.h"
#include "sead/heap.h"
#include "system/Application.h"

// no idea what this is for
static sead::Heap* someHeap = (sead::Heap*)0x7102522A28;

void nninitStartup()
{
    u64 allocatorBlock, recordingBlock;

    nn::os::SetMemoryHeapSize(0xC8000000);
    nn::os::AllocateMemoryBlock(&allocatorBlock, 0x2400000);
    nn::init::InitializeAllocator(&allocatorBlock, 0x2400000);
    nn::os::AllocateMemoryBlock(&recordingBlock, 0x6000000);
    nn::oe::EnableGamePlayRecording(&recordingBlock, 0x6000000);
}

void nnMain()
{
    s32 argC = nn::os::GetHostArgc();
    char** argV = nn::os::GetHostArgv();

    ApplicationFunction::initialize(argC, argV);

    if (sead::HeapMgr::sRootHeaps && someHeap != 0)
    {
        sead::Heap* heapMgrHeap = sead::HeapMgr::sInstancePtr->setCurrentHeap_(someHeap);
        Application::createInstance(0);

        // ...what?
        if (heapMgrHeap != (sead::Heap*)1)
        {
            sead::HeapMgr::sInstancePtr->setCurrentHeap_(heapMgrHeap);
        }
        else
        {
            Application::createInstance(0);
        }

        Application::sInstance->init(argC, argV);
        Application::sInstance->run();
    }
}