#include "cnf.h"
#include <string>
#include <sstream>

using namespace std;

CNF::CNF(int num_vars, int num_clauses) {
  this->num_vars = num_vars;
  this->num_clauses = num_clauses;
  this->pos_clauses.resize(num_clauses);
  this->neg_clauses.resize(num_clauses);
}

void CNF::insert(const vector<int> &clause, int clause_count) {
  for (int lit : clause) {
    int var = abs(lit);
    if (var_map.find(var) == var_map.end()) {
      unsigned int new_var = var_map.size();
      if (new_var >= num_vars)
        throw invalid_argument("Too many variables in CNF");

      var_map[var] = new_var;
      var_map_inv[new_var] = var;
    }
    if (lit > 0) {
      pos_clauses[clause_count][var_map[var]] = true;
    } else {
      neg_clauses[clause_count][var_map[var]] = true;
    }
  }
}

bool CNF::operator==(const CNF &other) const {
  if (num_vars != other.num_vars)
    return false;
  if (num_clauses != other.num_clauses)
    return false;
  for (auto it : other.var_map) {
    if (var_map.find(it.first) == var_map.end())
      return false;
    unsigned int loc_other = it.second;
    unsigned int loc_local = var_map.at(it.first);
    for (int i = 0; i < num_clauses; i++) {
      if (pos_clauses[i][loc_local] != other.pos_clauses[i][loc_other])
        return false;
      if (neg_clauses[i][loc_local] != other.neg_clauses[i][loc_other])
        return false;
    }
  }
  return true;
}

#ifdef DEBUG
std::ostream &operator<<(std::ostream &os, const std::vector<bool> &v) {
  os << "[";
  for (auto ii : v) {
    os << " " << (ii ? "1" : "0");
  }
  os << " ]";
  return os;
}

void CNF::show_cmp(const CNF &other) const {
  if (num_vars != other.num_vars)
    cout << "num_vars: " << num_vars << " != " << other.num_vars << endl;
  if (num_clauses != other.num_clauses)
    cout << "num_clauses: " << num_clauses << " != " << other.num_clauses
         << endl;
  for (auto it : other.var_map) {
    if (var_map.find(it.first) == var_map.end())
      cout << "var_map: " << it.first << " not found" << endl;
    unsigned int loc_other = it.second;
    unsigned int loc_local = var_map.at(it.first);
    for (int i = 0; i < num_clauses; i++) {
      if (pos_clauses[i][loc_local] != other.pos_clauses[i][loc_other])
        cout << "pos_clauses[" << i << "][" << loc_local << "]: "
             << pos_clauses[i][loc_local] << " != "
             << other.pos_clauses[i][loc_other] << endl;
      if (neg_clauses[i][loc_local] != other.neg_clauses[i][loc_other])
        cout << "neg_clauses[" << i << "][" << loc_local << "]: "
             << neg_clauses[i][loc_local] << " != "
             << other.neg_clauses[i][loc_other] << endl;
    }
  }
}

void CNF::print() const {
  cout << "num_vars: " << num_vars << endl;
  cout << "num_clauses: " << num_clauses << endl;
  for (auto it : var_map) {
    cout << "var_map: " << it.first << " -> " << it.second << endl;
  }
  for (int i = 0; i < this->num_clauses; i++) {
    cout << "pos_clauses[" << i << "]: " << pos_clauses[i] << endl;
    cout << "neg_clauses[" << i << "]: " << neg_clauses[i] << endl;
  }
  cout << endl;
}
#endif

CNF::CNF(istream &input) {
  string word;
  if (!(input >> word) || word != "p" || !(input >> word) || word != "cnf" || !(input >> num_vars)
      || !(input >> num_clauses)) {
    throw invalid_argument("Error: Input is in wrong format.");
  }

  this->pos_clauses.resize(num_clauses);
  this->neg_clauses.resize(num_clauses);
  for (int i = 0; i < num_clauses;) {
    pos_clauses[i] = vector<bool>(num_vars, false);
    neg_clauses[i] = vector<bool>(num_vars, false);
    int var;
    vector<int> clause;
    while (input >> var) {
      if (var == 0) {
        insert(clause, i);
        clause.clear();
        ++i;
        goto INCR;
      }
      clause.push_back(var);
    }
    if (i != num_clauses) {
      throw invalid_argument("Error: Input is not complete");
    }
    break;
    INCR:
    continue;
  }
}
bool CNF::satisfied(const vector<bool> &assignment) const {
  for (int i = 0; i < num_clauses; i++) {
    bool satisfied = false;
    for (int j = 0; j < num_vars; j++) {
      if (pos_clauses[i][j] && assignment[j]) {
        satisfied = true;
        break;
      }
      if (neg_clauses[i][j] && !assignment[j]) {
        satisfied = true;
        break;
      }
    }
    if (!satisfied)
      return false;
  }
  return true;
}
void CNF::print_case(const vector<bool> &assignment) {
  for (auto it : var_map) {
    cout << (assignment[it.second] ? "+" : "-") << it.first << " ";
  }
  cout << endl;
}





