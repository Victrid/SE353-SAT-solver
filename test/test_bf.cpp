#include <gtest/gtest.h>
#include <iostream>
#include "utils.h"
#include "cnf.h"
#include "test_utils.h"

using namespace std;

TEST(BruteForce, input1) {
  SKIP_IF_NOT_EXIST("test/cnf_examples/input1.cnf")
  CNF cnf(ifs);
  auto result = brute_force_searcher(cnf);
  EXPECT_TRUE(result.first);
  EXPECT_TRUE(cnf.satisfied(result.second));
}

TEST(BruteForce, input2) {
  SKIP_IF_NOT_EXIST("test/cnf_examples/input2.cnf")
  CNF cnf(ifs);
  auto result = brute_force_searcher(cnf);
  EXPECT_FALSE(result.first);
}

TEST(BruteForce, input3) {
  SKIP_IF_NOT_EXIST("test/cnf_examples/input3.cnf")
  CNF cnf(ifs);
  auto result = brute_force_searcher(cnf);
  EXPECT_TRUE(result.first);
  EXPECT_TRUE(cnf.satisfied(result.second));
}

TEST(BruteForce, input4) {
  SKIP_IF_NOT_EXIST("test/cnf_examples/input4.cnf")
  CNF cnf(ifs);
  auto result = brute_force_searcher(cnf);
  EXPECT_TRUE(result.first);
  EXPECT_TRUE(cnf.satisfied(result.second));
}