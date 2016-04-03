cmake_minimum_required(VERSION 2.8.9)

include_directories(Include Include/Algorithms)
 
set(
	SOURCES 
	Include/CALBidirectionalGraph.h
	Include/CALGraph.h
	Include/GraphTypeTraits.h
	Include/TCDFSIterator.h
	Include/TCDFSIterator.hpp
	Include/Algorithms/TCCycleAlgorithm.h
	Include/Algorithms/TCCycleAlgorithm.hpp
	Include/Algorithms/CCycleAlgorithmResult.h
	Source/CALBidirectionalGraph.cpp
	Source/CALGraph.cpp
	Source/Algorithms/CCycleAlgorithmResult.cpp
)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
 
add_library(GraphLib STATIC ${SOURCES})
source_group(
	Include\\Algorithms FILES
	Include/Algorithms/TCCycleAlgorithm.h
	Include/Algorithms/TCCycleAlgorithm.hpp
	Include/Algorithms/CCycleAlgorithmResult.h
)

source_group(
	Include FILES
	Include/CALBidirectionalGraph.h
	Include/CALGraph.h
	Include/GraphTypeTraits.h
	Include/TCDFSIterator.h
	Include/TCDFSIterator.hpp
)

source_group(
	Source FILES
	Source/CALBidirectionalGraph.cpp
	Source/CALGraph.cpp
)

source_group(
	Source\\Algorithms FILES
	Source/Algorithms/CCycleAlgorithmResult.cpp
)	
install(TARGETS GraphLib DESTINATION /usr/lib)
