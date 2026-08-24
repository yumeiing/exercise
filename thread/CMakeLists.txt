cmake_minimum_required(VERSION 3.5)
project(new)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

set(CMAKE_CXX_STANDARD 20) # you can use c++23 to use "std::print"
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(app ${SRC})
