cmake_minimum_required(VERSION 2.8)

add_library(add_new_lib SHARED ${CMAKE_CURRENT_SOURCE_DIR}/lib.h)

set(path ${CMAKE_CURRENT_SOURCE_DIR}/../lib )
