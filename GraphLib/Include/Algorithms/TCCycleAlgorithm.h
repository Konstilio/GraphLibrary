//
//  TCCycleAlgorithm.h
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/27/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#ifndef TCCycleAlgorithm_h
#define TCCycleAlgorithm_h
#include <type_traits>
#include "../GraphTypeTraits.h"

using namespace GraphTraits;

template <class Graph, class = typename std::enable_if<NotIsBidirectional_V<Graph>>::type>
class TCCycleAlgorithm {
    
public:
    Graph const* m_pGraph;
};


#endif /* TCCycleAlgorithm_h */
