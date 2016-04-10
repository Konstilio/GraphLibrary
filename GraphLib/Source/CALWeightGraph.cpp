//
//  CALBidirectionalGraph.cpp
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/26/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#include "../Include/CALWeightGraph.h"
#include <algorithm>

using namespace std;

CALWeightGraph::CALWeightGraph(size_t _N)
    : m_G(_N)
    , m_nEdges(0)
{
    
}


size_t CALWeightGraph::Vertexes() const
{
    return m_G.size();
}

size_t CALWeightGraph::Edges() const noexcept
{
    return m_nEdges;
}

void CALWeightGraph::AddVertex()
{
    m_G.resize(Vertexes() + 1);
}

void CALWeightGraph::AddEdge(uint32_t _V1, uint32_t _V2, uint32_t _Weight)
{
    m_G[_V1].push_back({_V2, _Weight});
    ++m_nEdges;
}

uint32_t CALWeightGraph::Weight(uint32_t _V1, uint32_t _V2) const
{
    auto List = m_G[_V1];
    auto it = find_if
                (
                    List.cbegin()
                    , List.cend()
                    , [_V2](CInternal const &_Data) -> bool
                    {
                        return _Data.m_Vertex == _V2;
                    }
                 )
                ;
    
    if (it == List.end())
        return std::numeric_limits<uint32_t>::max();
    
    return it->m_Weight;
}

size_t CALWeightGraph::AdjactentCount(uint32_t _V) const
{
    return m_G[_V].size();
}

bool CALWeightGraph::RemoveEdge(uint32_t _V1, uint32_t _V2)
{
    auto prevSizeV1 = m_G[_V1].size();
    
    m_G[_V1].remove_if([_V2](CInternal const &_Data) ->bool
                       {
                           return _Data.m_Vertex == _V2;
                       });
    
    auto newSizeV1 = m_G[_V1].size();
    if (prevSizeV1 > newSizeV1)
    {
        --m_nEdges;
        return true;
    }
    return false;
}

void CALWeightGraph::IsolateVertex(uint32_t _V)
{
    for (size_t i = 0; i < Vertexes(); ++i)
    {
        if (i == _V)
            continue;
        
        m_G[i].remove_if
        (
            [_V](CInternal const &_Data) ->bool
            {
                return _Data.m_Vertex == _V;
            }
        );
    }
    
    uint32_t sizeV = static_cast<uint32_t>(m_G[_V].size());
    m_G[_V].clear();
    m_nEdges -= sizeV;
}

//CDFSIterator<CALWeightGraph> CALWeightGraph::DFSIterator(uint32_t _V) const noexcept
//{
//    return CDFSIterator<CALWeightGraph>(*this, _V);
//}
