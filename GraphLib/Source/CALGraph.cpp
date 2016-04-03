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
    , m_nEdges(0)
{
    
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
    m_G[_V1].push_back(_V2);
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
    
    m_G[_V1].remove(_V2);
    
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
    for (size_t i = 0; i < _V; ++i)
        m_G[i].remove(_V);
    
    for (size_t i = _V + 1; i < Vertexes(); ++i)
        m_G[i].remove(_V);
    
    uint32_t sizeV = static_cast<uint32_t>(m_G[_V].size());
    m_G[_V].clear();
    m_nEdges -= sizeV;
}

CDFSIterator<CALGraph> CALGraph::DFSIterator(uint32_t _V) const noexcept
{
    return CDFSIterator<CALGraph>(*this, _V);
}
