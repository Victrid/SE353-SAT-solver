cmake_minimum_required(VERSION 3.21)

project(sat_solver)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)


add_executable(sat_solver ${SRC_FILES} src/brute_force.cpp)

enable_testing()
add_subdirectory(test)