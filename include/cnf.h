#ifndef SATSOLVER_SRC_CNF_H_
#define SATSOLVER_SRC_CNF_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>

struct CNF {
  unsigned int num_vars{};
  unsigned int num_clauses{};
  std::vector<std::vector<bool>> pos_clauses;
  std::vector<std::vector<bool>> neg_clauses;
  std::map<int, unsigned int> var_map;
  std::map<unsigned int, int> var_map_inv;

  CNF(int num_vars, int num_clauses);
  explicit CNF(std::istream &input);
  bool operator==(const CNF &other) const;
  void insert(const std::vector<int> &clause, int clause_count);
  [[nodiscard]] bool satisfied(const std::vector<bool> &assignment) const;
  void print_case(const std::vector<bool> &assignment);
#ifdef DEBUG
  void show_cmp(const CNF &other) const;
  void print() const;
#endif
};

typedef struct CNF CNF;

bool brute_force_solver(CNF &cnf);

#endif //SATSOLVER_SRC_CNF_H_
