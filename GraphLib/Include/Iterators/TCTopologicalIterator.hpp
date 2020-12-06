#ifndef CTopologicalIterator_hpp
#define CTopologicalIterator_hpp

#include "TCTopologicalIterator.h"

template<class Graph>
CTopologicalIterator<Graph>::CTopologicalIterator(Graph const &_Graph)
 : m_pGraph(_Graph)
 , m_Cache(_Graph.Vertexes(), WHITE)
{
}

template<class Graph>
bool CTopologicalIterator<Graph>::HasNext() const noexcept {
    if (m_Stack.empty()) {
        while (m_Index < m_Cache.size()) {
            if (m_Cache[m_Index] == WHITE) {
                m_Stack.push_back({m_Index, NodeType::BEGIN});
                return true;
            }
            ++m_Index;
        }
        
        return false;
    } else {
        auto const last = m_Stack.back();
    }
}

template<class Graph>
uint32_t CTopologicalIterator<Graph>::Next() {
    
}

#endif
