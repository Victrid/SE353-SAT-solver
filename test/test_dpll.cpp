#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "cnf.h"
#include "test_utils.h"

using namespace std;

TEST(DPLL, input1) {
  SKIP_IF_NOT_EXIST("test/cnf_examples/input1.cnf");
  CNF cnf(ifs);
  auto result = DPLL_searcher(cnf);
  EXPECT_TRUE(result.first);
  EXPECT_TRUE(cnf.satisfied(result.second));
}

TEST(DPLL, input2) {
  SKIP_IF_NOT_EXIST("test/cnf_examples/input2.cnf");
  CNF cnf(ifs);
  auto result = DPLL_searcher(cnf);
  EXPECT_FALSE(result.first);
}

TEST(DPLL, input3) {
  SKIP_IF_NOT_EXIST("test/cnf_examples/input3.cnf");
  CNF cnf(ifs);
  auto result = DPLL_searcher(cnf);
  EXPECT_TRUE(result.first);
  EXPECT_TRUE(cnf.satisfied(result.second));
}

TEST(DPLL, input4) {
  SKIP_IF_NOT_EXIST("test/cnf_examples/input4.cnf");
  CNF cnf(ifs);
  auto result = DPLL_searcher(cnf);
  EXPECT_TRUE(result.first);
  EXPECT_TRUE(cnf.satisfied(result.second));
}
