#include <string>
#include <filesystem>
namespace fs = std::filesystem;

#include <gtest/gtest.h>
#include "test_utils.h"
#include "utils.h"
#include "cnf.h"

#define TEST_BENCHMARK_SAT(suite, name, folder, searcher) \
TEST(suite, name) { \
  std::string path = "test/cnf_examples/" folder; \
  if (!fs::exists(path)) \
    GTEST_SKIP() << "Run Makefile to download dataset first."; \
  for (const auto &entry : fs::directory_iterator(path)) { \
    SKIP_IF_NOT_EXIST(entry.path()); \
    CNF cnf(ifs); \
    auto result = searcher(cnf); \
    EXPECT_TRUE(result.first); \
    EXPECT_TRUE(cnf.satisfied(result.second)); \
  } \
}

#define TEST_BENCHMARK_UNSAT(suite, name, folder, searcher) \
TEST(suite, name) { \
  std::string path = "test/cnf_examples/" folder; \
  if (!fs::exists(path)) \
    GTEST_SKIP() << "Run Makefile to download dataset first."; \
  for (const auto &entry : fs::directory_iterator(path)) { \
    SKIP_IF_NOT_EXIST(entry.path()); \
    CNF cnf(ifs); \
    auto result = searcher(cnf); \
    EXPECT_FALSE(result.first); \
  } \
}

TEST_BENCHMARK_SAT(BruteForce, uf20_91, "uf20-91", brute_force_searcher);
TEST_BENCHMARK_SAT(DPLL, uf20_91, "uf20-91", DPLL_searcher);

TEST_BENCHMARK_SAT(DPLL, uf50_218, "uf50-218", DPLL_searcher);
TEST_BENCHMARK_UNSAT(DPLL, uuf50_218, "uuf50-218", DPLL_searcher);