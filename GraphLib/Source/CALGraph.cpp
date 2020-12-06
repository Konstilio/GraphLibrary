//
//  CALBidirectionalGraph.cpp
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/26/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#include "../Include/CALGraph.h"
#include <algorithm>

using namespace std;

CALGraph::CALGraph(size_t _N)
    : m_G(_N)
    , m_ReversedG(_N)
    , m_nEdges(0)
{
    
}

CALGraph::CALGraph
(
    std::vector<std::unordered_set<uint32_t>> _G
    , std::vector<std::unordered_set<uint32_t>> _ReversedG
    , size_t _nEdges
)
    : m_G(_G)
    , m_ReversedG(_ReversedG)
    , m_nEdges(_nEdges)
{
}

bool CALGraph::operator==(CALGraph const &_Other) const {
    return m_G == _Other.m_G;
}

bool CALGraph::operator!=(CALGraph const &_Other) const {
    return m_G != _Other.m_G;
}

CALGraph CALGraph::ReversedGraph() const {
    return CALGraph(m_ReversedG, m_G, m_nEdges);
}

size_t CALGraph::Vertexes() const
{
    return m_G.size();
}

size_t CALGraph::Edges() const noexcept
{
    return m_nEdges;
}

void CALGraph::AddVertex()
{
    m_G.resize(Vertexes() + 1);
}

void CALGraph::AddEdge(uint32_t _V1, uint32_t _V2)
{
    m_G[_V1].insert(_V2);
    m_ReversedG[_V2].insert(_V1);
    ++m_nEdges;
}

bool CALGraph::IsAdjactent(uint32_t _V1, uint32_t _V2) const
{
    auto List = m_G[_V1];
    return find(List.cbegin(), List.cend(), _V2) != List.cend();
}

size_t CALGraph::AdjactentCount(uint32_t _V) const
{
    return m_G[_V].size();
}

bool CALGraph::RemoveEdge(uint32_t _V1, uint32_t _V2)
{
    auto prevSizeV1 = m_G[_V1].size();
    
    m_G[_V1].erase(_V2);
    m_ReversedG[_V2].erase(_V1);
    
    auto newSizeV1 = m_G[_V1].size();
    if (prevSizeV1 > newSizeV1)
    {
        --m_nEdges;
        return true;
    }
    return false;
}

void CALGraph::IsolateVertex(uint32_t _V)
{
    int nErased = 0;
    for (size_t i = 0; i < _V; ++i) {
        nErased += m_G[i].erase(_V);
        nErased += m_G[_V].erase(i);
        m_ReversedG[i].erase(_V);
        m_ReversedG[_V].erase(i);
    }
    
    for (size_t i = _V + 1; i < Vertexes(); ++i) {
        nErased += m_G[i].erase(_V);
        nErased += m_G[_V].erase(i);
        m_ReversedG[i].erase(_V);
        m_ReversedG[_V].erase(i);
    }
    
    m_nEdges -= nErased;
}

CALGraph::DFSIterator CALGraph::DFSBegin(uint32_t _V) const {
    return DFSIterator(*this, _V);
}

CALGraph::VertexIterator CALGraph::VertexItBegin(uint32_t _V) const {
    return VertexIterator(*this, _V);
}
