//
//  CALBidirectionalGraph.h
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/26/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#ifndef CALWeightGraph_h
#define CALWeightGraph_h

#include <vector>
#include <list>

class CALWeightGraph
{
    
public:
    CALWeightGraph(size_t _N);
    CALWeightGraph(CALWeightGraph const &_Other) =  default;
    CALWeightGraph& operator=(CALWeightGraph const &_Other) = default;
    CALWeightGraph(CALWeightGraph &&_Other) = default;
    CALWeightGraph& operator=(CALWeightGraph &_Other) = default;
    
    
    size_t Vertexes() const;
    size_t Edges() const noexcept;
    
    void AddVertex();
    void AddEdge(uint32_t _V1, uint32_t _V2, uint32_t _Weight);
    uint32_t Weight(uint32_t _V1, uint32_t _V2) const;
    size_t AdjactentCount(uint32_t _V) const;
    
    bool RemoveEdge(uint32_t _V1, uint32_t _V2);
    void IsolateVertex(uint32_t _V);
    
    //friend class CDFSIterator<CALWeightGraph>;
    //CDFSIterator<CALWeightGraph> DFSIterator(uint32_t _V) const noexcept;
    
    //algorithms
    template <class CALWeightGraph, class Is>
    friend class TCCycleAlgorithm;
    
private:
    
    struct CInternal
    {
        uint32_t m_Vertex;
        uint32_t m_Weight;
    };
    
    std::vector<std::list<CInternal>> m_G;
    size_t m_nEdges;
};




#endif /* CALWeightGraph_h */
