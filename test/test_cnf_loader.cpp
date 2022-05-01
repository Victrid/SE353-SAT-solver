#include <gtest/gtest.h>
#include <fstream>

#include "cnf.h"

using namespace std;
TEST(CnfLoader, detailed_input1) {
  ifstream ifs("test/cnf_examples/input1.cnf");
  CNF cnf(ifs);
  CNF expected(5, 5);
  expected.var_map[1] = 0;
  expected.var_map[2] = 1;
  expected.var_map[3] = 2;
  expected.var_map[4] = 3;
  expected.var_map[5] = 4;
  expected.pos_clauses[0] = vector<bool>{false, false, false, false, false};
  expected.neg_clauses[0] = vector<bool>{true, false, false, false, false};
  expected.pos_clauses[1] = vector<bool>{false, false, false, false, false};
  expected.neg_clauses[1] = vector<bool>{false, true, false, false, false};
  expected.pos_clauses[2] = vector<bool>{false, false, false, false, false};
  expected.neg_clauses[2] = vector<bool>{false, false, true, false, false};
  expected.pos_clauses[3] = vector<bool>{false, false, false, false, false};
  expected.neg_clauses[3] = vector<bool>{false, false, false, true, false};
  expected.pos_clauses[4] = vector<bool>{true, true, true, true, true};
  expected.neg_clauses[4] = vector<bool>{false, false, false, false, false};

  EXPECT_TRUE(cnf == expected);
}

TEST(CnfLoader, detailed_input2) {
  ifstream ifs("test/cnf_examples/input2.cnf");
  CNF cnf(ifs);
  CNF expected(3, 5);
  expected.var_map[1] = 0;
  expected.var_map[2] = 1;
  expected.var_map[3] = 2;
  expected.pos_clauses[0] = vector<bool>{false, false, false};
  expected.neg_clauses[0] = vector<bool>{true, true, false};
  expected.pos_clauses[1] = vector<bool>{true, false, false};
  expected.neg_clauses[1] = vector<bool>{false, true, false};
  expected.pos_clauses[2] = vector<bool>{false, true, true};
  expected.neg_clauses[2] = vector<bool>{false, false, false};
  expected.pos_clauses[3] = vector<bool>{true, true, false};
  expected.neg_clauses[3] = vector<bool>{false, false, true};
  expected.pos_clauses[4] = vector<bool>{false, true, false};
  expected.neg_clauses[4] = vector<bool>{true, false, true};

  EXPECT_TRUE(cnf == expected);
}

TEST(CnfLoader, can_load_input3) {
  ifstream ifs("test/cnf_examples/input3.cnf");
  CNF cnf(ifs);
}

TEST(CnfLoader, can_load_input4) {
  ifstream ifs("test/cnf_examples/input4.cnf");
  CNF cnf(ifs);
}

TEST(CnfLoader, not_complete) {
  ifstream ifs("test/cnf_examples/bad/not_complete.cnf");
  EXPECT_ANY_THROW(CNF cnf(ifs));
}

TEST(CnfLoader, var_unbound) {
  ifstream ifs("test/cnf_examples/var_unbound.cnf");
  EXPECT_ANY_THROW(CNF cnf(ifs));
}