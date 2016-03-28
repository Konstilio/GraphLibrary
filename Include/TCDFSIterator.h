//
//  CDFSIterator.hpp
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/26/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#ifndef CDFSIterator_h
#define CDFSIterator_h

#include <vector>

template<class Graph>
class CDFSIterator
{
    friend Graph;
public:
    CDFSIterator();
    CDFSIterator(CDFSIterator const &_Other) = default;
    CDFSIterator& operator=(CDFSIterator const &_Other) = default;
    
    bool HasNext() const noexcept;
    uint32_t Next();
    
private:
    CDFSIterator(Graph const &_Graph, uint32_t Vertex);
    
    Graph const* m_pGraph;
    uint32_t m_Vertex;
    std::vector<uint32_t> m_Stack;
    std::vector<bool> m_Used;
};

#include "TCDFSIterator.hpp"

#endif /* CDFSIterator_hpp */
