#include "cnf.h"
#include "utils.h"
#include "TracebackSolver.h"
#include "DPLLSolver.h"
using namespace std;

pair<bool, vector<bool>> brute_force_searcher(CNF &cnf) {
  TracebackSolver solver;
  auto result = solver.solve(cnf);
  vector<bool> assignment(cnf.num_vars, false);
  for (auto &lit : result.second)
    assignment[abs(lit) - 1] = lit > 0;
  return make_pair(result.first, assignment);
}

pair<bool, vector<bool>> DPLL_searcher(CNF &cnf) {
  DPLLSolver solver;
  auto result = solver.solve(cnf);
  vector<bool> assignment(cnf.num_vars, false);
  for (auto &lit : result.second)
    assignment[abs(lit) - 1] = lit > 0;
  return make_pair(result.first, assignment);
}