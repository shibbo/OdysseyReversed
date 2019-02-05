/**
 * @file Graph.h
 * @brief Storage for a graph that contains nodes.
 */

#pragma once

#include "types.h"

#include "sead/array.h"

namespace al
{
    class Graph
    {
    public:
        struct Vertex
        {
            sead::PtrArrayImpl _0;
            u32 _10;
            u32 _14;
        };

        class Edge
        {
        public:
            virtual f32 getWeight() const;

            u64 _8;
            u64 _10;
            f32 mWeight; // _18
        };

        Graph(s32 vertCount, s32 edgeCount);

        void appendVertex(s32 where);
        void appendVertex(al::Graph::Vertex *vert);
        void removeVertex(al::Graph::Vertex const *vert);
        void removeEdge(al::Graph::Edge *edge);
        al::Graph::Edge* tryFindEdge(s32 unk1, s32 unk2);

        sead::PtrArrayImpl mVertArray; // _0
        sead::PtrArrayImpl mEdgeArray; // _10
    };
};