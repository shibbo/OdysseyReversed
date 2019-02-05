/**
 * @file Graph.cpp
 * @brief Storage for a graph that contains nodes.
 */

#include "al/rail/Graph.h"

namespace al
{
    Graph::Graph(s32 vertCount, s32 edgeCount)
    {
        this->mEdgeArray.mBuffer = 0;
        this->mEdgeArray._0 = 0;
        this->mVertArray.mBuffer = 0;
        this->mEdgeArray._0 = 0;

        sead::PtrArrayImpl* vertArray = &this->mVertArray;
        sead::PtrArrayImpl* edgeArray = &this->mEdgeArray;

        vertArray->allocBuffer(vertCount, 0, 8);
        edgeArray->allocBuffer(edgeCount, 0, 8);
    }

    void Graph::appendVertex(s32 unk1)
    {
        Vertex* vert = (Vertex*)operator new(sizeof(Vertex));
        vert->_10 = this->mVertArray._0;
        vert->_0._0 = 0;
        vert->_0.mBuffer = 0;
        vert->_0.allocBuffer(unk1, 0, 8);

        if (this->mVertArray._0 < ((u64)this->mVertArray._0 >> 32))
        {
            *((Vertex*)this->mVertArray.mBuffer + ((u64)this->mVertArray._0 << 32 >> 29)) = *vert;
            ++this->mVertArray._0;
        }
    }

    void Graph::appendVertex(Vertex* vert)
    {
        if (this->mVertArray._0 < ((u64)this->mVertArray._0 >> 32))
        {
            *((Vertex*)this->mVertArray.mBuffer + ((u64)this->mVertArray._0 << 32 >> 29)) = *vert;
            ++this->mVertArray._0;
        }
    }

    void Graph::removeVertex(const Vertex* vert)
    {
        u32 v5;
        Vertex* v6;
        u32 v7, v8;
        sead::PtrArrayImpl* v9;
        u32 v10, v11, v12, v13;

        if (this->mVertArray._0 >= 1)
        {
            v5 = 0;
            while (1)
            {
                v6 = (this->mVertArray._0 <= v5 ? 0 : ((Vertex*)this->mVertArray.mBuffer + 8 * v5));

                if (v6 == vert)
                {
                    break;
                }

                if (++v5 >= this->mVertArray._0)
                {
                    return;
                }
            }
            v7 = vert->_0._0;
            if (vert->_0._0 >= 1)
            {
                v8 = 0;
                v9 = &this->mEdgeArray;
                do
                {
                    if (v7 <= v8)
                    {
                        v10 = 0;
                    }
                    else
                    {
                        v10 = *((u64*)vert->_0.mBuffer + 8 * v8);
                    }
                    v11 = v9->_0;
                    if (v11 >= 1)
                    {
                        v12 = 0;

                        while (1)
                        {
                            v13 = v11 <= v12 ? 0 : *((u64*)this->mEdgeArray.mBuffer + 8 * v12);
                            if (v13 == v10)
                            {
                                break;
                            }

                            if (++v12 >= v11)
                            {
                                this->mEdgeArray.erase(v12, 1);
                                v7 = vert->_0._0;
                                ++v8;
                                continue;
                            }
                        }
                        this->mEdgeArray.erase(v12, 1);
                        v7 = vert->_0._0;
                    }
                    ++v8;
                } 
                while (v8 < v7);
            }
            this->mVertArray.erase(v5, 1);
        }
    }

    void Graph::removeEdge(Edge* edge)
    {
        u32 curEdgeIdx = 0;
        Edge* curEdge;

        if (this->mEdgeArray._0 >= 1)
        {
            curEdgeIdx = 0;

            while(1)
            {
                curEdge = (Edge*)(this->mEdgeArray._0 <= curEdgeIdx ? 0 : *((u64*)this->mEdgeArray.mBuffer + 8 * curEdgeIdx));
                if (curEdge == edge)
                {
                    break;
                }

                if (++curEdgeIdx >= this->mEdgeArray._0)
                {
                    return;
                }
            }
            this->mEdgeArray.erase(curEdgeIdx, 1);
        }
    }

    al::Graph::Edge* Graph::tryFindEdge(s32 unk1, s32 unk2)
    {
        Edge* curEdge;
        u32 curEdgeIdx;

        if (this->mEdgeArray._0 < 1)
        {
            return 0;
        }

        curEdgeIdx = 0;

        while(1)
        {
            curEdge = (Edge*)(this->mEdgeArray._0 <= curEdgeIdx ? 0 : *(u64*)this->mEdgeArray.mBuffer + 8 * curEdgeIdx);

            if ((curEdge->_8 + 0x10) == unk1 && (curEdge->_10 + 0x10) == unk2)
            {
                break;
            }

            if (++curEdgeIdx >= this->mEdgeArray._0)
            {
                return 0;
            }
        }

        return curEdge;
    }

    f32 Graph::Edge::getWeight() const
    {
        return mWeight;
    }
};