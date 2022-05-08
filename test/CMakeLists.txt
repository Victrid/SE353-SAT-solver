find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/../src)

file(GLOB SRC_FILES ${src_dir}/*.cpp)
list(REMOVE_ITEM SRC_FILES ${src_dir}/cli.cpp)

file(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test_*)

add_executable(tester ${SRC_FILES} ${TEST_FILES})

target_link_libraries(tester
        ${GTEST_BOTH_LIBRARIES}
        pthread)

gtest_discover_tests(tester WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})