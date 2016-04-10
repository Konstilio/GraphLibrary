#ifndef CVertexIterator_h
#define CVertexIterator_h

#include "GraphTypeTraits.h"

class ACVertexIterator
{
public:
    virtual ~ACVertexIterator() = 0;
    
    virtual bool HasNext() const noexcept = 0;
    uin32_t Next() = 0;
};

template <class Graph = typename std::enable_if_t<NotIsWeighted_V<Graph>>>
class TCVertexIterator : public ACVertexIterator
{
    
};

#include "TCVertexIterator.hpp"

#endif