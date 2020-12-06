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
#include <unordered_set>
#include <Iterators/TCDFSIterator.h>
#include <Iterators/TCVertexIterator.h>

class CALGraph
{
    
public:
    using DFSIterator = TCDFSIterator<CALGraph>;
    using VertexIterator = TCVertexIterator<CALGraph>;
    
    CALGraph(size_t _N);
    CALGraph(CALGraph const &_Other) =  default;
    CALGraph& operator=(CALGraph const &_Other) = default;
    CALGraph(CALGraph &&_Other) = default;
    CALGraph& operator=(CALGraph &_Other) = default;
    
    bool operator==(CALGraph const &_Other) const;
    bool operator!=(CALGraph const &_Other) const;
    
    CALGraph ReversedGraph() const;
    
    size_t Vertexes() const;
    size_t Edges() const noexcept;
    
    void AddVertex();
    void AddEdge(uint32_t _V1, uint32_t _V2);
    bool IsAdjactent(uint32_t _V1, uint32_t _V2) const;
    size_t AdjactentCount(uint32_t _V) const;
    
    bool RemoveEdge(uint32_t _V1, uint32_t _V2);
    void IsolateVertex(uint32_t _V);
    
    template<class Graph>
    friend class CDFSIterator;
    
    DFSIterator DFSBegin(uint32_t _V) const;
    
    template<class Graph>
    friend class TCVertexIterator;
    
    VertexIterator VertexItBegin(uint32_t _V) const;
    
    //algorithms
    template <class Graph, class Is>
    friend class TCCycleAlgorithm;
    
private:
    
    CALGraph
    (
        std::vector<std::unordered_set<uint32_t>> _G
        , std::vector<std::unordered_set<uint32_t>> _ReversedG
        , size_t _nEdges
     );
    
    std::vector<std::unordered_set<uint32_t>> m_G;
    std::vector<std::unordered_set<uint32_t>> m_ReversedG;
    size_t m_nEdges;
};




#endif /* CALGraph_h */
