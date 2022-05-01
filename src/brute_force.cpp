//
// Created by victrid on 22-5-2.
//

#include "cnf.h"
#include "utils.h"
using namespace std;

bool brute_force_solver(CNF &cnf) {
  unsigned int var_num = cnf.num_vars;
  unsigned int max_avail = (1 << var_num) - 1;
  for (unsigned int i = 0; i <= max_avail; i++) {
    vector<bool> assignment = from_int(i, var_num);
    if (cnf.satisfied(assignment)) {
#ifdef DEBUG
      cnf.print_case(assignment);
#endif
      return true;
    }
  }
  return false;
}