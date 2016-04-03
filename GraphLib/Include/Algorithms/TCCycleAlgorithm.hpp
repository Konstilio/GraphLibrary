//
//  TCCycleAlgorithm.hpp
//  GraphLibrary
//
//  Created by Aleksander Konstantinov on 3/27/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#ifndef TCCycleAlgorithm_hpp
#define TCCycleAlgorithm_hpp

template <class Graph, class Is>
TCCycleAlgorithm<Graph, Is>::TCCycleAlgorithm(Graph const &_Graph)
    : mp_pGraph(&_Graph)
    , mp_Data(mp_pGraph->Vertexes())
{
    
}

template <class Graph, class Is>
CCycleAlgorithmResult TCCycleAlgorithm<Graph, Is>::operator()()
{
    for (size_t iVer = 0; iVer < mp_pGraph->Vertexes(); ++iVer)
    {
        if (mp_Data[iVer].m_Color == EColor::EColor_White)
        {
            if (fp_DFS(iVer))
                break;
        }
    }
    
    if (mp_Start != -1)
    {
        uint32_t Start = static_cast<uint32_t>(mp_Start);
        uint32_t End = static_cast<uint32_t>(mp_End);
        
        std::vector<uint32_t> path;
        path.push_back(Start);
        for (auto v = End ; v != Start; v = mp_Data[v].m_Parent)
            path.push_back(v);
        path.push_back(Start);
        
        return CCycleAlgorithmResult(true, std::move(path));
    }
    
    return CCycleAlgorithmResult(false, std::vector<uint32_t>());
}

template <class Graph, class Is>
bool TCCycleAlgorithm<Graph, Is>::fp_DFS(uint32_t _Vertex)
{
    mp_Data[_Vertex].m_Color = EColor::EColor_Gray;
    auto it = mp_pGraph->m_G[_Vertex].begin();
    auto itEnd = mp_pGraph->m_G[_Vertex].end();
    
    for (; it != itEnd; ++it)
    {
        auto to = *it;
        if (mp_Data[to].m_Color == EColor::EColor_White)
        {
            mp_Data[to].m_Parent = _Vertex;
            if (fp_DFS(to))
                return true;
        }
        else if (mp_Data[to].m_Color == EColor::EColor_Gray)
        {
            mp_Start = to;
            mp_End = _Vertex;
            return true;
        }
    }
    
    mp_Data[_Vertex].m_Color = EColor::EColor_Black;
    return false;
}

#include "TCCycleAlgorithm.h"


#endif /* TCCycleAlgorithm_hpp */
