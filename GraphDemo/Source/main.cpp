#include <iostream>
#include <CALBidirectionalGraph.h>
#include <CALGraph.h>
#include <CALWeightGraph.h>
#include <Algorithms/TCCycleAlgorithm.h>
#include <GraphConfig>
using namespace std;

int main()
{
//    CALBidirectionalGraph bg(5);
//    bg.AddEdge(0, 1);
//    bg.AddEdge(0, 2);
//    bg.AddEdge(1, 3);
//    bg.AddEdge(2, 3);
//    bg.AddEdge(1, 4);
//    bg.AddEdge(2, 4);
//    bg.AddEdge(3, 4);
//    CDFSIterator<CALBidirectionalGraph> it(bg, 0);
//    while (it.HasNext())
//    {
//        cout << it.Next() << '\n';
//    }
    
    CALGraph g(5);
    g.AddEdge(0, 1);
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(1, 4);
    CALGraph::DFSIterator it = g.DFSBegin(0);
    while (it.HasNext())
    {
        cout << it.Next() << '\n';
    }
    
    TCCycleAlgorithm<CALGraph> tc = g;
    auto tcResult = tc();
    
    cout << "----------------------------------------------" << endl;
    
    if (tcResult.Cycle()) {
        cout << "g has Cycle" << endl;
        auto path = tcResult.Path();
        cout << path << endl;
    } else {
        cout << "g does not have Cycle" << endl;
    }
    
    
    g.AddEdge(1, 0);
    
    TCCycleAlgorithm<CALGraph> tc1 = g;
    tcResult = tc1();
    if (tcResult.Cycle()) {
        cout << "g has Cycle" << endl;
        auto path = tcResult.Path();
        cout << path << endl;
    } else {
        cout << "g does not have Cycle" << endl;
    }
    
    CALWeightGraph gw(2);
    
    cout << "----------------------------------------------" << endl;
//    TCVertexIterator<CALGraph> vIt(g, 1);
//    while (vIt.HasNext())
//        cout << vIt.Next() << ' ';
//    cout << endl;
//    
//    cout << "----------------------------------------------" << endl;
//    TCVertexIterator<CALBidirectionalGraph> vIt1(bg, 0);
//    while (vIt1.HasNext())
//        cout << vIt1.Next() << ' ';
//    cout << endl;
    
    cout << "GraphLib_VERSION_MAJOR = " << GraphLib_VERSION_MAJOR;
    
    return 0;
}
