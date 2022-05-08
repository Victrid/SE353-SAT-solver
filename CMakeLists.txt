cmake_minimum_required(VERSION 3.21)

project(sat_solver)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release
RelWithDebInfo MinSizeRel."
      FORCE)
    message(STATUS "CMAKE_BUILD_TYPE is not set, using Release")
endif(NOT CMAKE_BUILD_TYPE)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/cli.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)


add_executable(sat_solver ${SRC_FILES} ${PROJECT_SOURCE_DIR}/src/cli.cpp)

enable_testing()
add_subdirectory(test)