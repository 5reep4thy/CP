/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: sreepat2
PROG: PROB
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;
ofstream fout ("PROB.out");
ifstream fin ("PROB.in");

void solve() {
  int n;
  fin >> n;
  vector<string> names;
  map<string, int> mp;
  map<string, int> csh;
  string tmp;
  for (int i = 0; i < n; i++) {
    fin >> tmp;
    names.push_back(tmp);
  }
  for (int i = 0; i < n; i++) {
    fin >> tmp;
    int c, d;
    fin >> c >> d;
    csh[tmp] -= c;
    if (d == 0) {
      csh[tmp] += c;
      continue;
    }
    csh[tmp] += c % d; 
    int times = d;
    while (times--) {
      fin >> tmp;
      csh[tmp] += c / d;
    }

  }
  for (int i = 0; i < n; i++) {
    fout << names[i] << " " << csh[names[i]] << "\n";
  }
}
int main() {
  int tests = 1;
  /* fin >> tests; */
  while (tests--) solve();
  return 0;
}
