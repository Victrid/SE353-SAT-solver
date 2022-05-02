find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/../src)
add_executable(tester test_cnf_loader.cpp ${src_dir}/loader.cpp ${src_dir}/solvers.cpp
        test_utils.cpp ${src_dir}/utils.cpp test_bf.cpp ${src_dir}/TracebackSolver.cpp
        ${src_dir}/DPLLSolver.cpp test_dpll.cpp test_utils.h standard-benchmarks.cpp)

target_link_libraries(tester
        ${GTEST_BOTH_LIBRARIES}
        pthread)

gtest_discover_tests(tester WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})