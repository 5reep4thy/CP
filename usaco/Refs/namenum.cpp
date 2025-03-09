/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: sreepat2
PROG: namenum
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;
ofstream fout ("namenum.out");
ifstream fin ("namenum.in");
ifstream dict ("dict.txt");
#ifdef _DEBUG
#include "local_helper.cpp"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long
#define int8_t int
map<int, vector<char>> vals;

vector<string> generateNames(vector<int> nos) {
  vector<int> nos2;
  vector<string> fnames;
  for (int i = 1; i < nos.size(); i++) 
    nos2.push_back(nos[i]);
  if (nos.size() == 0)
    return {""};
  else {
    vector<string> names = generateNames(nos2);
    for (int i = 0; i < names.size(); i++) {
      for (int j = 0; j < 3; j++) {
        string x = vals[nos[0]][j] + names[i];
        fnames.push_back(x);
      }
    }
  }
  return fnames;

}
void solve() {
  string s;
  fin >> s;
  vals[2] = {'A', 'B', 'C'};
  vals[3] = {'D', 'E', 'F'};
  vals[4] = {'G', 'H', 'I'};
  vals[5] = {'J', 'K', 'L'};
  vals[6] = {'M', 'N', 'O'};
  vals[7] = {'P', 'R', 'S'};
  vals[8] = {'T', 'U', 'V'};
  vals[9] = {'X', 'Y', 'Z'};
  int n = s.size();
  vector<int> vals;
  for (int i = 0; i < n; i++) {
    string x(1, s[i]);
    vals.push_back(atoi(x.c_str()));
  }
  vector<string> names = generateNames(vals);
  set<string> listedNames;
  string tmp;
  for (int i = 0; i < 4617; i++) {
    dict >> tmp;
    listedNames.insert(tmp);
  }

  bool found = 0;
  vector<string> ans;
  for (auto name: names) {
    if (listedNames.find(name) != listedNames.end()) {
      ans.push_back(name);
      found = 1;
    }
  }
  if (!found) {
    fout << "NONE\n";
    return;
  }
  sort(ans.begin(), ans.end());
  for (int i =0; i < ans.size(); i++) {
    fout << ans[i] << "\n";
  }

}
int main() {
  int tests = 1;
  /* fin >> tests; */
  while (tests--) solve();
  return 0;
}
