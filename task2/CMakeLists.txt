cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(tech2)

include_directories(
    PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${GTEST_INCLUDE_DIRS}
)


execute_process(COMMAND python3 preparing.py WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/A)

set(SOURCE "./C/main.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(C ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp)
add_subdirectory(B)


target_link_libraries(C  add_new_lib)

