#include <gtest/gtest.h>
#include <fstream>
#include "utils.h"

using namespace std;

TEST(utils, test_bool_from_int_0) {
  auto t = from_int(0, 4);
  ASSERT_EQ(t, std::vector<bool>({0, 0, 0, 0}));
}

TEST(utils, test_bool_from_int_1) {
  auto t = from_int(1, 4);
  ASSERT_EQ(t, std::vector<bool>({0, 0, 0, 1}));
}

TEST(utils, test_bool_from_int_2) {
  auto t = from_int(2, 4);
  ASSERT_EQ(t, std::vector<bool>({0, 0, 1, 0}));
}

TEST(utils, test_bool_from_int_3) {
  auto t = from_int(10, 4);
  ASSERT_EQ(t, std::vector<bool>({1, 0, 1, 0}));
}

TEST(utils, main_func_bad_parameter_1) {
  testing::internal::CaptureStdout();
  const char *argvalue[] = {"test", "test_utils.cpp"};
  __entrypoint(2, const_cast<char **>(argvalue));
  string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "Usage: test [ brute | dpll ] <cnf_file>\n");
}

TEST(utils, main_func_bad_parameter_2) {
  testing::internal::CaptureStdout();
  const char *argvalue[] = {"test", "brute"};
  __entrypoint(2, const_cast<char **>(argvalue));
  string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "Usage: test [ brute | dpll ] <cnf_file>\n");
}

TEST(utils, main_func_bad_parameter_3) {
  testing::internal::CaptureStdout();
  const char *argvalue[] = {"test", "asdf", "test/cnf_examples/input2.cnf"};
  __entrypoint(3, const_cast<char **>(argvalue));
  string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "Usage: test [ brute | dpll ] <cnf_file>\n");
}

TEST(utils, main_func_parameter_brute_unsat) {
  testing::internal::CaptureStdout();
  const char *argvalue[] = {"test", "brute", "test/cnf_examples/input2.cnf"};
  __entrypoint(3, const_cast<char **>(argvalue));
  string output = testing::internal::GetCapturedStdout();
  vector<string> lines;
  {
    string ostr;
    stringstream ss(output);
    while (getline(ss, ostr)) {
      lines.push_back(ostr);
    }
  }
  ASSERT_EQ(lines.size(), 1);
  ASSERT_EQ(lines[0], "s UNSATISFIABLE");
}

TEST(utils, main_func_parameter_dpll_unsat) {
  testing::internal::CaptureStdout();
  const char *argvalue[] = {"test", "dpll", "test/cnf_examples/input2.cnf"};
  __entrypoint(3, const_cast<char **>(argvalue));
  string output = testing::internal::GetCapturedStdout();
  vector<string> lines;
  {
    string ostr;
    stringstream ss(output);
    while (getline(ss, ostr)) {
      lines.push_back(ostr);
    }
  }
  ASSERT_EQ(lines.size(), 1);
  ASSERT_EQ(lines[0], "s UNSATISFIABLE");
}

TEST(utils, main_func_parameter_brute_sat) {
  testing::internal::CaptureStdout();
  const char *argvalue[] = {"test", "brute", "test/cnf_examples/input3.cnf"};
  __entrypoint(3, const_cast<char **>(argvalue));
  string output = testing::internal::GetCapturedStdout();
  cout << output;
  vector<string> lines;
  {
    string ostr;
    stringstream ss(output);
    while (getline(ss, ostr)) {
      lines.push_back(ostr);
    }
  }
  ASSERT_EQ(lines.size(), 2);
  ASSERT_EQ(lines[0], "s SATISFIABLE");
  vector<int> assignment;
  {
    char ochr = 0;
    int t;
    stringstream ss(lines[1]);
    ss >> ochr;
    if(ochr != 'v'){
      FAIL() << ochr;
    }
    while (ss >> t) {
      assignment.push_back(t);
    }
  }
  ifstream in("test/cnf_examples/input3.cnf");
  CNF cnf(in);
  ASSERT_TRUE(cnf.satisfied(assignment));
}


TEST(utils, main_func_parameter_dpll_sat) {
  testing::internal::CaptureStdout();
  const char *argvalue[] = {"test", "dpll", "test/cnf_examples/input3.cnf"};
  __entrypoint(3, const_cast<char **>(argvalue));
  string output = testing::internal::GetCapturedStdout();
  vector<string> lines;
  {
    string ostr;
    stringstream ss(output);
    while (getline(ss, ostr)) {
      lines.push_back(ostr);
    }
  }
  ASSERT_EQ(lines.size(), 2);
  ASSERT_EQ(lines[0], "s SATISFIABLE");
  vector<int> assignment;
  {
    char ochr;
    int t;
    stringstream ss(lines[1]);
    ss >> ochr;
    if(ochr != 'v'){
      FAIL() << ochr;
    }
    while (ss >> t) {
      assignment.push_back(t);
    }
  }
  ifstream in("test/cnf_examples/input3.cnf");
  CNF cnf(in);
  ASSERT_TRUE(cnf.satisfied(assignment));
}