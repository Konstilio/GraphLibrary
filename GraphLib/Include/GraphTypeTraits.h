//
//  GraphTypeTraits.h
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/27/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#ifndef GraphTypeTraits_h
#define GraphTypeTraits_h
#include <type_traits>
#include "CALBidirectionalGraph.h"
#include "CALGraph.h"

namespace std {
    template< bool B, class T = void >
    using enable_if_t = typename enable_if<B,T>::type;
}

namespace GraphTraits {
    
    //
    // IsBidirectional
    //
    
    template <class Graph>
    struct IsBidirectional
    {
        static constexpr bool Value = false;
    };
    
    template<>
    struct IsBidirectional<CALBidirectionalGraph>
    {
        static constexpr bool Value = true;
    };
    
    template<class Graph>
    constexpr bool IsBidirectional_V = IsBidirectional<Graph>::Value;
    
    template<class Graph>
    constexpr bool NotIsBidirectional_V = !IsBidirectional_V<Graph>;
}


#endif /* GraphTypeTraits_h */
