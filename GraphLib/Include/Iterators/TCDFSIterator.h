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
class TCDFSIterator
{
    friend Graph;
public:
    TCDFSIterator();
    TCDFSIterator(Graph const &_Graph, uint32_t _Vertex);
    TCDFSIterator(TCDFSIterator const &_Other) = default;
    TCDFSIterator& operator=(TCDFSIterator const &_Other) = default;
    
    bool HasNext() const noexcept;
    uint32_t Next();
    
private:
    void fp_ProcessVertex(uint32_t _Vertex);
    
    Graph const* m_pGraph;
    uint32_t m_Vertex;
    std::vector<uint32_t> m_Stack;
    std::vector<bool> m_Used;
};

#include "TCDFSIterator.hpp"

#endif /* CDFSIterator_hpp */
