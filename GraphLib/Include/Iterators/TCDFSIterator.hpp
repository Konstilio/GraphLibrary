//
//  Header.h
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/26/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#ifndef CDFSIterator_hpp
#define CDFSIterator_hpp
#include "TCDFSIterator.h"
#include "TCVertexIterator.h"

template<class Graph>
TCDFSIterator<Graph>::TCDFSIterator()
    : m_pGraph(nullptr)
    , m_Vertex(0)
    , m_Stack()
    , m_Used()
{
}

template<class Graph>
TCDFSIterator<Graph>::TCDFSIterator(Graph const &_Graph, uint32_t Vertex)
    : m_pGraph(&_Graph)
    , m_Vertex(Vertex)
    , m_Used(_Graph.Vertexes(), false)
{
    m_Used[m_Vertex] = true;
    m_Stack.push_back(m_Vertex);
}

template<class Graph>
bool TCDFSIterator<Graph>::HasNext() const noexcept
{
    return !m_Stack.empty();
}

template<class Graph>
uint32_t TCDFSIterator<Graph>::Next()
{
    uint32_t ret = m_Stack[m_Stack.size() - 1];
    m_Stack.pop_back();
    fp_ProcessVertex(ret);
    return ret;
    
}

template<class Graph>
void TCDFSIterator<Graph>::fp_ProcessVertex(uint32_t _Vertex)
{
    TCVertexIterator<Graph> VertexIt(*m_pGraph, _Vertex);
    while (VertexIt.HasNext()) {
        auto curr = VertexIt.Next();
        if (!m_Used[curr])
        {
            m_Used[curr] = true;
            m_Stack.push_back(curr);
        }
    }
}

#endif //CDFSIterator_hpp


