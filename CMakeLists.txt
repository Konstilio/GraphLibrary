cmake_minimum_required(VERSION 2.8.9)
project(Graph)

include_directories(Include Include/Algorithms)
 
set(SOURCES 
Include/CALBidirectionalGraph.h
Include/GraphTypeTraits.h
Include/TCDFSIterator.h
Include/TCDFSIterator.hpp
Include/Algorithms/TCCycleAlgorithm.h
Include/Algorithms/TCCycleAlgorithm.hpp
Source/CALBidirectionalGraph.cpp)

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
 
add_library(GraphLibrary STATIC ${SOURCES})
install(TARGETS GraphLibrary DESTINATION /usr/lib)
