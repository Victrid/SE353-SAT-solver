#include <map>
#include "DPLLSolver.h"

using namespace std;

void DPLLSolver::modify(vector<map<unsigned int, bool>> &clauses, vector<int> &result) {
  unit_propagate(clauses, result);
  pure_literal_elimination(clauses, result);
}

void DPLLSolver::unit_propagate(vector<map<unsigned int, bool>> &clauses, vector<int> &result) {
  bool modified = true;
  while (modified) {
    modified = false;
    for (auto it = clauses.begin(); it != clauses.end(); it++) {
      if (it->size() == 1) {
#ifdef VERBOSE_DEBUG
        cout << "unit_propagate: " << it->begin()->first << endl;
#endif
        modified = true;
        auto &lit_val = *it->begin();
        auto var = lit_val.first;
        auto value = lit_val.second;
        result.push_back(lit_val.second ? var + 1 : -var - 1);
        clauses.erase(it);

        for (auto clause = clauses.begin(); clause != clauses.end();) {
          if (clause->find(var) != clause->end()) {
            if ((*clause)[var] == value) {
              clause = clauses.erase(clause);
            } else {
              clause->erase(var);
              ++clause;
            }
          } else {
            ++clause;
          }
        }

        break;
      }
    }
  }

}

void DPLLSolver::pure_literal_elimination(vector<map<unsigned int, bool>> &clauses,
                                          vector<int> &result) {
  map<unsigned int, pair<bool, bool>> pure_literals;
  for (auto &clause : clauses)
    for (auto &lit_val : clause) {
      if (pure_literals.find(lit_val.first) == pure_literals.end()) {
        // Not found
        pure_literals[lit_val.first] = make_pair(true, lit_val.second);
      } else if (pure_literals[lit_val.first].second != lit_val.second)
        pure_literals[lit_val.first].first = false;
    };

  for (auto &pure_literal : pure_literals) {
    if (!pure_literal.second.first)
      continue;
#ifdef VERBOSE_DEBUG
    cout << "pure_literal_elimination: " << pure_literal.first << endl;
#endif
    auto lit_val = make_pair(pure_literal.first, pure_literal.second.second);
    result.push_back(lit_val.second ? lit_val.first + 1 : -lit_val.first - 1);
    for (auto it = clauses.begin(); it != clauses.end();) {
      if (it->find(lit_val.first) != it->end())
        it = clauses.erase(it);
      else
        it++;
    }
  }
}
