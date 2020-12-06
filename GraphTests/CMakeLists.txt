cmake_minimum_required(VERSION 3.0)
set(
	SOURCES
	Base.h
	test_graph.cpp
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(GraphTests ${SOURCES})
add_test(graph test_graph)
target_include_directories(GraphTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(GraphTests GraphLib) 
