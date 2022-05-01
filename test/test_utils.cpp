#include <gtest/gtest.h>
#include <fstream>
#include "utils.h"

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
