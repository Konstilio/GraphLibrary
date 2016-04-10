#include <iostream>
#include "../../GraphLib/Include/CALBidirectionalGraph.h"
#include "../../GraphLib/Include/CALGraph.h"
#include "../../GraphLib/Include/CALWeightGraph.h"
#include "../../GraphLib/Include/TCVertexIterator.h"
#include "../../GraphLib/Include/Algorithms/TCCycleAlgorithm.h"
using namespace std;

int main()
{
    CALBidirectionalGraph bg(5);
    bg.AddEdge(0, 1);
    bg.AddEdge(0, 2);
    bg.AddEdge(1, 3);
    bg.AddEdge(2, 3);
    bg.AddEdge(1, 4);
    bg.AddEdge(2, 4);
    bg.AddEdge(3, 4);
    auto it = bg.DFSIterator(0);
    while (it.HasNext())
    {
        cout << it.Next() << '\n';
    }
    
    CALGraph g(5);
    g.AddEdge(0, 1);
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(1, 4);
    
    
    TCCycleAlgorithm<CALGraph> tc = g;
    auto tcResult = tc();
    
    cout << "----------------------------------------------" << endl;
    
    cout << tcResult.Cycle() << endl;
    
    CALGraph g1(2);
    g.AddEdge(0, 1);
    
    TCCycleAlgorithm<CALGraph> tc1 = g1;
    tcResult = tc1();
    cout << tcResult.Cycle() << endl;
    
    CALWeightGraph gw(2);
    
    cout << "----------------------------------------------" << endl;
    TCVertexIterator<CALGraph> vIt(g, 1);
    while (vIt.HasNext())
        cout << vIt.Next() << ' ';
    cout << endl;
    
    cout << "----------------------------------------------" << endl;
    TCVertexIterator<CALBidirectionalGraph> vIt1(bg, 0);
    while (vIt1.HasNext())
        cout << vIt1.Next() << ' ';
    cout << endl;
    

    
    return 0;
}