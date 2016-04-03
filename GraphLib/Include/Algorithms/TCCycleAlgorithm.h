//
//  TCCycleAlgorithm.h
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/27/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#ifndef TCCycleAlgorithm_h
#define TCCycleAlgorithm_h
#include <vector>
#include "../GraphTypeTraits.h"
#include "CCycleAlgorithmResult.h"

using namespace GraphTraits;

template <class Graph, class = typename std::enable_if_t<NotIsBidirectional_V<Graph>>>
class TCCycleAlgorithm {
public:
    TCCycleAlgorithm(Graph const &_Graph);
    
    CCycleAlgorithmResult operator()();
    
private:
    bool fp_DFS(uint32_t _Vertex);
    
    enum class EColor : uint8_t
    {
        EColor_White = 0,
        EColor_Gray = 1,
        EColor_Black = 2
    };
    
    struct CINternal
    {
        uint32_t m_Parent;
        EColor m_Color;
        
        CINternal()
        : m_Parent(-1)
        , m_Color(EColor::EColor_White)
        {}
    };
    
    Graph const *mp_pGraph;
    std::vector<CINternal> mp_Data;
    int64_t mp_Start = -1;
    int64_t mp_End = -1;
};

#include "TCCycleAlgorithm.hpp"

#endif /* TCCycleAlgorithm_h */
