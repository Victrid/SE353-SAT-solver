#ifndef SAT_SOLVER_TEST_TEST_UTILS_H

#include <fstream>

#define SKIP_IF_NOT_EXIST(path) \
  std::ifstream ifs(path); \
  if (!ifs.good()) GTEST_SKIP();

#define SAT_SOLVER_TEST_TEST_UTILS_H

#endif //SAT_SOLVER_TEST_TEST_UTILS_H
