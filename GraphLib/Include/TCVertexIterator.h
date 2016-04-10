#ifndef CVertexIterator_h
#define CVertexIterator_h

#include "GraphTypeTraits.h"

template <class Graph, bool IsWeighted>
class TCVertexIterator_Imp
{
public:
    TCVertexIterator_Imp(Graph const &_G, uint32_t _V);
    bool HasNext();
    uint32_t Next();
};

template<class Graph>
using TCVertexIterator = TCVertexIterator_Imp<Graph, GraphTraits::IsWeighted_V<Graph>>;

#include "TCVertexIterator.hpp"

#endif //CVertexIterator_h