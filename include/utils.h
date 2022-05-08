#ifndef SAT_SOLVER_SRC_UTILS_H
#define SAT_SOLVER_SRC_UTILS_H
#include <vector>
#include "cnf.h"

std::vector<bool> from_int(unsigned int n, unsigned int size);

std::pair<bool, std::vector<bool>> brute_force_searcher(CNF &cnf);
std::pair<bool, std::vector<bool>> DPLL_searcher(CNF &cnf);
int __entrypoint(int argc, char **argv);
#endif //SAT_SOLVER_SRC_UTILS_H
