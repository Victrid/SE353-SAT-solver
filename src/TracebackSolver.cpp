#include "TracebackSolver.h"

using namespace std;
pair<bool, vector<int>> TracebackSolver::solve(CNF &cnf) {
  vector<map<unsigned int, bool>> clauses;
  for (int i = 0; i < cnf.num_clauses; ++i) {
    map<unsigned int, bool> clause;
    for (unsigned int j = 0; j < cnf.num_vars; j++) {
      if (cnf.pos_clauses[i][j]) {
        clause[j] = true;
      } else if (cnf.neg_clauses[i][j]) {
        clause[j] = false;
      }
    }
    clauses.emplace_back(clause);
  }
  return solve(clauses);
}

// Backtrace traversing:
// 1. If no clauses exists, then all eliminated and return
// 2. If there exists a clause that is not satisfied: return false.

pair<bool, vector<int>> TracebackSolver::solve(vector<map<unsigned int, bool>> &clauses) {
#ifdef VERBOSE_DEBUG
  cout << "Solving with " << clauses.size() << " clauses" << endl;
  for (auto &clause : clauses) {
    cout << "Clause: ";
    for (auto &var : clause) {
      cout << (var.second? "" : "-") << var.first << " ";
    }
    cout << endl;
  }
#endif
  vector<int> result;
  modify(clauses, result);
  if (clauses.empty())
    return make_pair(true, move(result));

  for (auto &clause : clauses)
    if (clause.empty())
      return make_pair(false, move(result));

  auto choose_res = choose_literal(clauses);
  if (!choose_res.first)
    return make_pair(false, move(result));

  auto new_lit = choose_res.second;
#ifdef VERBOSE_DEBUG
  cout << "Chosen literal: " << new_lit << endl;
#endif
  auto child_res = solve(clauses, new_lit, true);

  if (child_res.first) {
    result.insert(result.end(),
                  make_move_iterator(child_res.second.begin()),
                  make_move_iterator(child_res.second.end()));
    result.push_back(new_lit + 1);
    return make_pair(true, move(result));
  }

  child_res = solve(clauses, new_lit, false);

  if (child_res.first) {
    result.insert(result.end(),
                  make_move_iterator(child_res.second.begin()),
                  make_move_iterator(child_res.second.end()));
    result.push_back(-1 - new_lit);
    return make_pair(true, move(result));
  }

  return make_pair(false, move(result));
}
pair<bool, unsigned int> TracebackSolver::choose_literal(const vector<map<unsigned int, bool>> &clauses) {
  // Choose the first one.
  for (auto &clause : clauses)
    for (auto &lit : clause)
      return make_pair(true, lit.first);
  return make_pair(false, 0);
}

pair<bool, vector<int>> TracebackSolver::solve(vector<map<unsigned int, bool>> &clauses,
                                               unsigned int var,
                                               bool value) {
  vector<map<unsigned int, bool>> new_clauses(clauses);

  for (auto clause = new_clauses.begin(); clause != new_clauses.end();) {
    if (clause->find(var) != clause->end()) {
      if ((*clause)[var] == value) {
        clause = new_clauses.erase(clause);
      } else {
        clause->erase(var);
        ++clause;
      }
    } else {
      ++clause;
    }
  }

  return solve(new_clauses);
}

void TracebackSolver::modify(vector<map<unsigned int, bool>> &clauses, vector<int> &result) {
}
