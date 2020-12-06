cmake_minimum_required(VERSION 3.0)
project(GraphLib VERSION 1.0)
configure_file(Config/GraphConfig.h.in GraphConfig)
 
set(
	SOURCES 
	Include/CALBidirectionalGraph.h
	Include/CALGraph.h
	Include/CALWeightGraph.h
	Include/GraphTypeTraits.h
	Include/Iterators/TCDFSIterator.h
	Include/Iterators/TCDFSIterator.hpp
	Include/Iterators/TCVertexIterator.h
	Include/Iterators/TCVertexIterator.hpp
	Include/Iterators/TCTopologicalIterator.h
	Include/Iterators/TCTopologicalIterator.hpp
	Include/Algorithms/TCCycleAlgorithm.h
	Include/Algorithms/TCCycleAlgorithm.hpp
	Include/Algorithms/CCycleAlgorithmResult.h
	Include/Algorithms/CPath.h
	Source/CALBidirectionalGraph.cpp
	Source/CALGraph.cpp
	Source/CALWeightGraph.cpp
	Source/Algorithms/CCycleAlgorithmResult.cpp
	Source/Algorithms/CPath.cpp
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
 
add_library(GraphLib STATIC ${SOURCES})
target_include_directories(GraphLib PUBLIC Include Include/Algorithms ${PROJECT_BINARY_DIR} PRIVATE Include/Iterators)
source_group(
	Include\\Algorithms FILES
	Include/Algorithms/TCCycleAlgorithm.h
	Include/Algorithms/TCCycleAlgorithm.hpp
	Include/Algorithms/CCycleAlgorithmResult.h
	Include/Algorithms/CPath.h
)

source_group(
	Include\\Iterators FILES
	Include/Iterators/TCDFSIterator.h
	Include/Iterators/TCDFSIterator.hpp
	Include/Iterators/TCVertexIterator.h
	Include/Iterators/TCVertexIterator.hpp
	Include/Iterators/TCTopologicalIterator.h
	Include/Iterators/TCTopologicalIterator.hpp
)

source_group(
	Include FILES
	Include/CALBidirectionalGraph.h
	Include/CALGraph.h
	Include/CALWeightGraph.h
	Include/GraphTypeTraits.h
)

source_group(
	Source FILES
	Source/CALBidirectionalGraph.cpp
	Source/CALGraph.cpp
	Source/CALWeightGraph.cpp
)

source_group(
	Source\\Algorithms FILES
	Source/Algorithms/CCycleAlgorithmResult.cpp
	Source/Algorithms/CPath.cpp
)	
install(TARGETS GraphLib DESTINATION /usr/lib)
