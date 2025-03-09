/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: sreepat2
PROG: dualpal
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;
ofstream fout ("dualpal.out");
ifstream fin ("dualpal.in");
#ifdef _DEBUG
#include "local_helper.cpp"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long
#define int8_t int
void solve() {
  int n, s;
  fin >> n >> s;
  auto ispal = [] (int n) {
    int orign = n;
    int ans = 0;
    for (int bas = 2; bas <= 10; bas++) {
      string rep;
      n = orign;
      while (n > 0) {
        rep += (char) ('0' + (n % bas));
        n /= bas;
      }
      int sz = rep.size();
      debug(orign, rep); 
      bool prob = 0;
      if (sz == 0)
        continue;
      for (int i = 0; i <= sz / 2; i++) {
        if (rep[i] != rep[sz - i - 1]) {
          prob = 1;
        }
      }
      if (!prob) {
        ans++;
      }
    }
    if (ans >= 2)
      return 1;
    return 0;
  };
  for (int i = s + 1; n > 0; i++) {
    if (ispal(i)) {
      n--;
      fout << i << "\n";
    }
  }

}
int main() {
  int tests = 1;
  /* fin >> tests; */
  while (tests--) solve();
  return 0;
}
