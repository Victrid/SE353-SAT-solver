#include "utils.h"
#include <vector>

using namespace std;

vector<bool> from_int(unsigned int n, unsigned int size) {
  vector<bool> res;
  for (int i = size - 1; i >= 0; i--)
    res.push_back(n & (1 << i));
  return res;
}

