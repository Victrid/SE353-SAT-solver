#ifndef SAT_SOLVER_SRC_DPLLSOLVER_H
#define SAT_SOLVER_SRC_DPLLSOLVER_H

#include "TracebackSolver.h"

class DPLLSolver : public TracebackSolver {
private:
  static void unit_propagate(std::vector<std::map<unsigned int, bool>> &clauses, std::vector<int> &result);
  static void pure_literal_elimination(std::vector<std::map<unsigned int, bool>> &clauses, std::vector<int> &result);
protected:
  void modify(std::vector<std::map<unsigned int, bool>> &clauses, std::vector<int> &result) override;
};

#endif //SAT_SOLVER_SRC_DPLLSOLVER_H
