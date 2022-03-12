cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(tech2)

include_directories(
  PUBLIC
  ${CMAKE_SOURCE_DIR}
  )

execute_process(COMMAND python3 preparing.py WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/A)

add_executable(C ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp)
add_custom_target(create DEPENDS index.h)
add_dependencies(C create)

add_subdirectory(B)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

target_link_libraries(C  add_new_lib)



