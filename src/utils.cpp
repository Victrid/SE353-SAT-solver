#include "utils.h"
#include <vector>
#include <fstream>

using namespace std;

vector<bool> from_int(unsigned int n, unsigned int size) {
  vector<bool> res;
  for (int i = size - 1; i >= 0; i--)
    res.push_back(n & (1 << i));
  return res;
}

int __entrypoint(int argc, char **argv) {
  if (argc != 3 ||
      !(string(argv[1]) == string("brute") ||
          string(argv[1]) == string("dpll"))) {
    cout << "Usage: " << argv[0] << " [ brute | dpll ] <cnf_file>" << endl;
    return 1;
  }
  string file_name = argv[2];

  ifstream ifs(file_name);
  if (!ifs.is_open()) {
    printf("Failed to open file %s\n", file_name.c_str());
    return 1;
  }

  CNF cnf(ifs);
  auto result = string(argv[2]) == "brute" ? brute_force_searcher(cnf) : DPLL_searcher(cnf);
  if (result.first) {
    cout << "s SATISFIABLE" << endl;
    cout << "v ";
    cnf.print_case(result.second);
    cout << endl;
  } else {
    cout << "s UNSATISFIABLE" << endl;
  }
  return 0;
}