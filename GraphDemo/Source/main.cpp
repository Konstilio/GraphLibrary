#include <iostream>
#include "../../GraphLib/Include/CALBidirectionalGraph.h"
#include "../../GraphLib/Include/Algorithms/TCCycleAlgorithm.h"
using namespace std;

int main()
{
    CALBidirectionalGraph g(5);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 3);
    g.AddEdge(2, 3);
    g.AddEdge(1, 4);
    g.AddEdge(2, 4);
    g.AddEdge(3, 4);
    auto it = g.DFSIterator(0);
    while (it.HasNext())
    {
        cout << it.Next() << '\n';
    }
    
    TCCycleAlgorithm<CALGraph> tc;
    
    return 0;
}