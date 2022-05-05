cmake_minimum_required(VERSION 3.0)

add_library(add_new_lib SHARED 
	${CMAKE_CURRENT_SOURCE_DIR}/lib.h
	${CMAKE_CURRENT_SOURCE_DIR}/lib.cpp)

set(path ${CMAKE_CURRENT_SOURCE_DIR}/../lib )
