/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: sreepat2
PROG: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;
ofstream fout ("beads.out");
ifstream fin ("beads.in");
void solve() {
  int n;
  fin >> n;
  string s;
  fin >> s;
  int ans = 0;
  for (int i = 0; i <= n + 1; i++) {
    int r = 0;
    int j = i;
    if (i == 28) {
      ;
    }
    while (s[j % n] == 'w' && j < n) {
      r++;
      j++;
    }
    char rc = s[j % n];
    for (; j < n + i; j++) {
      if (s[j % n] == rc || s[(j + n) %n ] == 'w') {
        r++;
      }
      else
        break;
    }
    int l = 0;
    j = i - 1;
    while (s[j % n] == 'w' && j < n) {
      l++;
      j--;
    }
    char lc = s[(j + n) % n];
    for (; j > i - n; j--) {
      if (s[(j + n) % n] == lc || s[(j + n) % n] == 'w') {
        l++;
      }
      else
        break;
    }
    ans = max(ans, l + r);
  }
  fout << min(n, ans) << "\n";

}
int main() {
  int tests = 1;
  /* fin >> tests; */
  while (tests--) solve();
  return 0;
}
