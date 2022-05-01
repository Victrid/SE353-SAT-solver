#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "cnf.h"

using namespace std;

TEST(BruteForce, input1) {
  ifstream ifs("test/cnf_examples/input1.cnf");
  CNF cnf(ifs);
  EXPECT_TRUE(brute_force_solver(cnf));
}

TEST(BruteForce, input2) {
  ifstream ifs("test/cnf_examples/input2.cnf");
  CNF cnf(ifs);
  EXPECT_FALSE(brute_force_solver(cnf));
}

TEST(BruteForce, input3) {
  ifstream ifs("test/cnf_examples/input3.cnf");
  CNF cnf(ifs);
  EXPECT_TRUE(brute_force_solver(cnf));
}

TEST(BruteForce, input4) {
  ifstream ifs("test/cnf_examples/input4.cnf");
  CNF cnf(ifs);
  EXPECT_TRUE(brute_force_solver(cnf));
}