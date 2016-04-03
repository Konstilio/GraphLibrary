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

template<class Graph>
CDFSIterator<Graph>::CDFSIterator()
    : m_pGraph(nullptr)
    , m_Vertex(0)
    , m_Stack()
    , m_Used()
{
}

template<class Graph>
CDFSIterator<Graph>::CDFSIterator(Graph const &_Graph, uint32_t Vertex)
    : m_pGraph(&_Graph)
    , m_Vertex(Vertex)
    , m_Used(_Graph.Vertexes(), false)
{
    m_Used[m_Vertex] = true;
    fp_ProcessVertex(m_Vertex);
}

template<class Graph>
bool CDFSIterator<Graph>::HasNext() const noexcept
{
    return !m_Stack.empty();
}

template<class Graph>
uint32_t CDFSIterator<Graph>::Next()
{
    uint32_t ret = m_Stack[m_Stack.size() - 1];
    m_Stack.pop_back();
    fp_ProcessVertex(ret);
    return ret;
    
}

template<class Graph>
void CDFSIterator<Graph>::fp_ProcessVertex(uint32_t _Vertex)
{
    for (auto it = m_pGraph->m_G[_Vertex].rbegin(); it != m_pGraph->m_G[_Vertex].rend(); ++it)
    {
        if (!m_Used[*it])
        {
            m_Used[*it] = true;
            m_Stack.push_back(*it);
        }
    }
}

#endif //CDFSIterator_hpp


