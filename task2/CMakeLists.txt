cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(tech2)

include_directories(
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${GTEST_INCLUDE_DIRS}
)

add_custom_command( OUTPUT index.h COMMAND python3 "${CMAKE_CURRENT_SOURCE_DIR/A/preparing.py" )

add_executable(C ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp)

add_subdirectory(B)

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/bin)

target_link_libraries(C  add_new_lib)
target_link_libraries( CTest ${GTEST_LIBRARIES} Threads::Threads add_new_lib)



