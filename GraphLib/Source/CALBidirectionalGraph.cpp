//
//  CALBidirectionalGraph.cpp
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/26/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#include "../Include/CALBidirectionalGraph.h"
#include <algorithm>

using namespace std;

CALBidirectionalGraph::CALBidirectionalGraph(size_t _N)
    : m_G(_N)
    , m_nEdges(0)
{
    
}

bool CALBidirectionalGraph::operator==(CALBidirectionalGraph const &_Other) const {
    return m_G == _Other.m_G;
}

bool CALBidirectionalGraph::operator!=(CALBidirectionalGraph const &_Other) const {
    return m_G != _Other.m_G;
}

size_t CALBidirectionalGraph::Vertexes() const
{
    return m_G.size();
}

size_t CALBidirectionalGraph::Edges() const noexcept
{
    return m_nEdges;
}

void CALBidirectionalGraph::AddVertex()
{
    m_G.resize(Vertexes() + 1);
}

void CALBidirectionalGraph::AddEdge(uint32_t _V1, uint32_t _V2)
{
    m_G[_V1].insert(_V2);
    m_G[_V2].insert(_V1);
    ++m_nEdges;
}

bool CALBidirectionalGraph::IsAdjactent(uint32_t _V1, uint32_t _V2) const
{
    auto List = m_G[_V1];
    return find(List.cbegin(), List.cend(), _V2) != List.cend();
}

size_t CALBidirectionalGraph::AdjactentCount(uint32_t _V) const
{
    return m_G[_V].size();
}

bool CALBidirectionalGraph::RemoveEdge(uint32_t _V1, uint32_t _V2)
{
    auto prevSizeV1 = m_G[_V1].size();
    
    m_G[_V1].erase(_V2);
    m_G[_V2].erase(_V1);
    
    auto newSizeV1 = m_G[_V1].size();
    if (prevSizeV1 > newSizeV1)
    {
        --m_nEdges;
        return true;
    }
    return false;
}

void CALBidirectionalGraph::IsolateVertex(uint32_t _V)
{
    for (size_t i = 0; i < _V; ++i) {
        m_G[i].erase(_V);
    }
    
    for (size_t i = _V + 1; i < Vertexes(); ++i) {
        m_G[i].erase(_V);
    }
        
    
    uint32_t sizeV = static_cast<uint32_t>(m_G[_V].size());
    m_G[_V].clear();
    m_nEdges -= sizeV;
}

CALBidirectionalGraph::DFSIterator CALBidirectionalGraph::DFSBegin(uint32_t _V) const {
    return DFSIterator(*this, _V);
}

CALBidirectionalGraph::VertexIterator CALBidirectionalGraph::VertexItBegin(uint32_t _V) const {
    return VertexIterator(*this, _V);
}
