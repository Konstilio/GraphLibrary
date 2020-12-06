#include "Base.h"
#include <iostream>
#include <Algorithms/TCCycleAlgorithm.h>
#include <CALGraph.h>
#include <CALWeightGraph.h>
#include <TCVertexIterator.h>
#include <TCDFSIterator.h>`
#include <GraphConfig>

using namespace test;

void testBasic()
{
  // do some nice calculation; store the results in `foo` and `bar`,
  // respectively

  ASSERT_EQUAL( 2.0, 2.0 );
  ASSERT_EQUAL( 2.0, 1.0 );
}

void testAdvanced()
{
  // a more advanced test
}

int main(int, char**)
{
  testBasic();
  testAdvanced();
}
