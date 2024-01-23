#include<bits/stdc++.h>
#include <boost/algorithm/string/classification.hpp>
#include <cstdlib>
#include <stdexcept>
#include <boost/algorithm/string.hpp>
using namespace std;

#define bsplit boost::algorithm::split 
void get_input(int argc, char** argv, string& correctcpp, string& wrongcpp, string& generatorcpp, int& no_of_tests) {
  correctcpp = "", wrongcpp = "", generatorcpp = "";
  no_of_tests = 1;
  char val_type;
  bool is_val = 0;
  
  for (int i = 0; i < argc; i++) {
    if (i == 0)
      continue;
    string inp = static_cast<string>(argv[i]);
    if (inp[0] != '-' && !is_val) {
      cout << "Wrong usage - Correct usage \"cpptester -g generator.cpp -t 12 -c correct.cpp -w wrong.cpp\" \n";
      exit(1);
    }
    if (inp[0] == '-' && is_val) {
      cout << "Wrong usage - Correct usage \"cpptester -g generator.cpp -t 12 -c correct.cpp -w wrong.cpp\" \n";
      exit(1);
    }

    if (inp[0] == '-' && !is_val) {
      is_val = 1;
      val_type = inp[1];
      continue;
    }
    if (is_val) {
      if (val_type == 'c') {
        correctcpp = inp;
        is_val = 0;
      }
      else if (val_type == 'g') {
        generatorcpp = inp;
        is_val = 0;
      }
      else if (val_type == 'w') {
        wrongcpp = inp;
        is_val = 0;
      }
      else if (val_type == 't') {
        try {
          no_of_tests = stoi(inp);
        }
        catch (invalid_argument arg)  {
          cout << "[Error] Tests accept integer only\n";
          exit(1);
        }
        is_val = 0;
      }
      else {
        cout << "Wrong usage - Correct usage \"cpptester -g generator.cpp -t 12 -c correct.cpp -w wrong.cpp\" \n";
        exit(1);
      }
    }
  }
  if (correctcpp == "" || wrongcpp == "" || generatorcpp == "") {
      cout << "Wrong usage - Correct usage \"cpptester -g generator.cpp -t 12 -c correct.cpp -w wrong.cpp\" \n";
      exit(1);
  }
}
bool check_contents(vector<string>& cor_lits, vector<string>& wro_lits) {
  ifstream fptr_cor, fptr_wro;
  fptr_cor.open(".tmpout_cor");
  fptr_wro.open(".tmpout_wro");
  string line;
  while (fptr_cor) {
    getline(fptr_cor, line); 
    vector<string> lits;
    bsplit(lits, line, boost::is_any_of(" ,\n"));
    for (auto& lit: lits) 
      if (lit.size() > 0)
        cor_lits.push_back(lit);
  }
  while (fptr_wro) {
    getline(fptr_wro, line); 
    vector<string> lits;
    bsplit(lits, line, boost::is_any_of(" ,\n"));
    for (auto& lit: lits) 
      if (lit.size() > 0)
        wro_lits.push_back(lit);
  }
  if (wro_lits.size() != cor_lits.size()) {
    cout << "Problem in output formats\n";
    exit(1);
  }
  for (int i = 0; i < wro_lits.size(); i++) {
    if (wro_lits[i] == cor_lits[i])
      continue;
    return 0;
  }
  return 1;
}
int main (int argc, char** argv) {
  string correctcpp, wrongcpp, generatorcpp;
  int no_of_tests;
  int cnt = 0, found_cnt = 0;
  int mx_tries = 10;
  get_input(argc, argv, correctcpp, wrongcpp, generatorcpp, no_of_tests);
  string compile_all = "$CXX -std=c++17 " + generatorcpp + " -o generatorcpp && $CXX -std=c++17 " + correctcpp + " -o correctcpp && $CXX -std=c++17 " + wrongcpp + " -o wrongcpp";
  while (found_cnt < no_of_tests && cnt < mx_tries) {
    system(compile_all.c_str());
    string cmd_gen = "./generatorcpp > .tmpin";
    system(cmd_gen.c_str());
    string cmd_test_cor = "./correctcpp < .tmpin > .tmpout_cor ";
    string cmd_test_wro = "./wrongcpp < .tmpin > .tmpout_wro ";
    system(cmd_test_cor.c_str());
    system(cmd_test_wro.c_str());
    vector<string> cor_contents, wro_contents;
    bool is_ok = check_contents(cor_contents, wro_contents);
    cnt++;
    if (!is_ok) {
      found_cnt++;
      string cmd_cpy = "mkdir -p conflict_tests && cat .tmpin > ./conflict_tests/" + to_string(cnt) + ".txt"; 
      system(cmd_cpy.c_str());
    }
  }
  cout << "Found " << found_cnt << " examples from " << cnt << " tries\n";
  return 0;
}
