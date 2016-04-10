#ifndef CVertexIterator_hpp
#define CVertexIterator_hpp

#include "TCVertexIterator.h"
#include "CALGraph.h"

template <class Graph>
class TCVertexIterator_Imp<Graph, false>
{
public:
    TCVertexIterator_Imp(Graph const &_G, uint32_t _V)
        : m_It(_G.m_G[_V].cbegin())
        , m_End(_G.m_G[_V].cend())
    {
    }
    
    bool HasNext()
    {
        return m_It != m_End;
    }
    
    uint32_t Next()
    {
        return *m_It++;
    }

private:
    std::list<uint32_t>::const_iterator m_It;
    std::list<uint32_t>::const_iterator m_End;
};


#endif //CVertexIterator_hpp