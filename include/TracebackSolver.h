#ifndef SAT_SOLVER_SRC_TRACEBACKSOLVER_H
#define SAT_SOLVER_SRC_TRACEBACKSOLVER_H

#include "cnf.h"

class TracebackSolver {
protected:
  std::pair<bool, std::vector<int>> solve(std::vector<std::map<unsigned int, bool>> &clauses);
  std::pair<bool, std::vector<int>> solve(std::vector<std::map<unsigned int, bool>> &clauses, unsigned int var,
                                          bool value);
  virtual void modify(std::vector<std::map<unsigned int, bool>> &clauses, std::vector<int> &result);
  static std::pair<bool, unsigned int> choose_literal(const std::vector<std::map<unsigned int, bool>> &clauses);
public:
  std::pair<bool, std::vector<int>> solve(CNF &cnf);
};

#endif //SAT_SOLVER_SRC_TRACEBACKSOLVER_H
