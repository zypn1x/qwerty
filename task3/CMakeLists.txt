cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-c++)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

project(SimpleLibrary)


include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)

add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)

install(TARGETS MainLib Main RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS MainLib Main LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(TARGETS MainLib Main ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION ${CMAKE_INSTALL_PREFIX})
