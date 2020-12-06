//
//  CDFSIterator.hpp
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 5/12/20.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#ifndef CTopologicalIterator_h
#define CTopologicalIterator_h

template<class Graph>
class CTopologicalIterator
{
public:
    CTopologicalIterator(Graph const &_Graph);
    CTopologicalIterator(CDFSIterator const &_Other) = default;
    CTopologicalIterator& operator=(CDFSIterator const &_Other) = default;
    
    bool HasNext() const noexcept;
    uint32_t Next();
    
private:
    enum class NodeType {BEGIN, END};
    enum State {WHITE = 0, GRAY = 1, BLACK = 2};
    struct CInternal {
        uint32_t m_Vertex;
        NodeType m_type
    }
    
    uint32 m_Index = 0;
    Graph const* m_pGraph;
    std::vector<CInternal> m_Stack;
    std::vector<State> m_Cache;
};

#include "TCTopologicalIterator.hpp"

#endif /* CDFSIterator_hpp */
