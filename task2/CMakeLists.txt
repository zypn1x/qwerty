cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(tech2)

execute_process(COMMAND python3 preparing.py WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/A)

add_executable(C ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp)

add_subdirectory(B)

set(path_to_bin ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(C  add_new_lib)


