//
//  CALBidirectionalGraph.h
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/26/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#ifndef CALGraph_h
#define CALGraph_h

#include <vector>
#include <list>
#include "TCDFSIterator.h"
#include "Algorithms/TCCycleAlgorithm.h"

class CALGraph
{
    
public:
    CALGraph(size_t _N);
    CALGraph(CALGraph const &_Other) =  default;
    CALGraph& operator=(CALGraph const &_Other) = default;
    CALGraph(CALGraph &&_Other) = default;
    CALGraph& operator=(CALGraph &_Other) = default;
    
    
    size_t Vertexes() const;
    size_t Edges() const noexcept;
    
    void AddVertex();
    void AddEdge(uint32_t _V1, uint32_t _V2);
    bool IsAdjactent(uint32_t _V1, uint32_t _V2) const;
    size_t AdjactentCount(uint32_t _V) const;
    
    bool RemoveEdge(uint32_t _V1, uint32_t _V2);
    void IsolateVertex(uint32_t _V);
    
    friend class CDFSIterator<CALGraph>;
    CDFSIterator<CALGraph> DFSIterator(uint32_t _V) const noexcept;
    
    //algorithms
    template <class Graph, class Is>
    friend class TCCycleAlgorithm;
    
private:
    std::vector<std::list<uint32_t>> m_G;
    size_t m_nEdges;
};




#endif /* CALGraph_h */
