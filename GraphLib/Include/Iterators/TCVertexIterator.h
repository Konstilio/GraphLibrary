#ifndef CVertexIterator_h
#define CVertexIterator_h

template <class Graph>
class TCVertexIterator
{
public:
    TCVertexIterator(Graph const &_G, uint32_t _V);
    bool HasNext();
    uint32_t Next();
    
private:
    std::unordered_set<uint32_t>::const_iterator m_It;
    std::unordered_set<uint32_t>::const_iterator m_End;
};

#include "TCVertexIterator.hpp"

#endif //CVertexIterator_h
