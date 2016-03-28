//
//  CALBidirectionalGraph.h
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/26/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#ifndef CALBidirectionalGraph_h
#define CALBidirectionalGraph_h

#include <vector>
#include <list>
#include "TCDFSIterator.h"

class CALBidirectionalGraph
{
    
public:
    CALBidirectionalGraph(size_t _N);
    CALBidirectionalGraph(CALBidirectionalGraph const &_Other) =  default;
    CALBidirectionalGraph& operator=(CALBidirectionalGraph const &_Other) = default;
    CALBidirectionalGraph(CALBidirectionalGraph &&_Other) = default;
    CALBidirectionalGraph& operator=(CALBidirectionalGraph &_Other) = default;
    
    
    size_t Vertexes() const;
    size_t Edges() const noexcept;
    
    void AddVertex();
    void AddEdge(uint32_t _V1, uint32_t _V2);
    bool IsAdjactent(uint32_t _V1, uint32_t _V2) const;
    size_t AdjactentCount(uint32_t _V) const;
    
    bool RemoveEdge(uint32_t _V1, uint32_t _V2);
    void IsolateVertex(uint32_t _V);
    
    friend class CDFSIterator<CALBidirectionalGraph>;
    CDFSIterator<CALBidirectionalGraph> DFSIterator(uint32_t _V) const noexcept;
    
    
private:
    std::vector<std::list<uint32_t>> m_G;
    size_t m_nEdges;
};




#endif /* CALBidirectionalGraph_h */
