#include "Base.h"
#include <iostream>
#include <Algorithms/TCCycleAlgorithm.h>
#include <CALGraph.h>
#include <CALBidirectionalGraph.h>
#include <CALWeightGraph.h>
#include <GraphConfig>

CALGraph buidListGraph();
CALGraph buidReverseListGraph();

using namespace test;

void testBasic()
{
  // do some nice calculation; store the results in `foo` and `bar`,
  // respectively
}

void testAdvanced()
{
  // a more advanced test
}

void testBidirectional() {
    CALGraph gr = buidListGraph();
    CALGraph expectedReversedGr = buidReverseListGraph();
    CALGraph reversedGr = gr.ReversedGraph();
    ASSERT_EQUAL_NO_STRING(reversedGr, expectedReversedGr);
    ASSERT_NOT_EQUAL_NO_STRING(gr, reversedGr);
}

void testTopological() {
    CALGraph graph = buidReverseListGraph();
}

CALGraph buidListGraph() {
    CALGraph graph{10};
    
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 5);
    graph.AddEdge(5, 6);
    graph.AddEdge(6, 7);
    graph.AddEdge(7, 8);
    graph.AddEdge(8, 9);
    
    return graph;
}

CALGraph buidReverseListGraph() {
    CALGraph graph{10};
    
    graph.AddEdge(9, 8);
    graph.AddEdge(8, 7);
    graph.AddEdge(7, 6);
    graph.AddEdge(6, 5);
    graph.AddEdge(5, 4);
    graph.AddEdge(4, 3);
    graph.AddEdge(3, 2);
    graph.AddEdge(2, 1);
    graph.AddEdge(1, 0);
    
    return graph;
}

int main(int, char**)
{
    testBasic();
    testAdvanced();
    testTopological();
    testBidirectional();
}
