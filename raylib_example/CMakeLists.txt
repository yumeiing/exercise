cmake_minimum_required(VERSION 3.5)
project(SDL_EXAMPLE)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(raylib)

add_executable(app ${SRC})

target_link_libraries(app raylib)
