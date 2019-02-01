#include "sead/heap.h"

namespace sead
{
    IDisposer::IDisposer()
    {
        this->_10 = 0;
        this->_18 = 0;
        this->mHeapPtr = 0;

        if (HeapMgr::sInstancePtr)
        {
            this->mHeapPtr = HeapMgr::sInstancePtr->findContainHeap(this);

            if (this->mHeapPtr)
            {
                this->mHeapPtr->appendDisposer_(this);
            }
        }
    }

    IDisposer::IDisposer(sead::Heap *heap, sead::IDisposer::HeapNullOption nullOption)
    {
        this->_10 = 0;
        this->_18 = 0;
        this->mHeapPtr = heap;

        sead::Heap* newHeap;

        if (heap)
        {
            heap->appendDisposer_(this);
            return;
        }

        if (nullOption >= IDisposer::HeapNullOption::UNKNOWN_2)
        {
            if (nullOption != IDisposer::HeapNullOption::UNKNOWN_3)
            {
                return;
            }

            if (!HeapMgr::sInstancePtr)
                return;

            newHeap = HeapMgr::sInstancePtr->getCurrentHeap();
        }
        else
        {
            if (!HeapMgr::sInstancePtr)
                return;

            newHeap = HeapMgr::sInstancePtr->findContainHeap(this);
        }
        
        this->mHeapPtr = newHeap;

        if (newHeap)
            this->mHeapPtr->appendDisposer_(this);
    }

    IDisposer::~IDisposer()
    {
        this->mHeapPtr->removeDisposer_(this);
        // what??
        //this->mHeapPtr = 1;
    }
};