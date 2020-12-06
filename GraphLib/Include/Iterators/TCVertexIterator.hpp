#ifndef CVertexIterator_hpp
#define CVertexIterator_hpp

#include "TCVertexIterator.h"

template<class Graph>
TCVertexIterator<Graph>::TCVertexIterator(Graph const &_Graph, uint32_t Vertex)
    : m_It(_Graph.m_G[Vertex].cbegin())
    , m_End(_Graph.m_G[Vertex].cend())
{
}

template<class Graph>
bool TCVertexIterator<Graph>::HasNext()
{
    return m_It != m_End;
}

template<class Graph>
uint32_t TCVertexIterator<Graph>:: Next()
{
    return *m_It++;
}



#endif //CVertexIterator_hpp
