/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: sreepat2
PROG: palsquare
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;
ofstream fout ("palsquare.out");
ifstream fin ("palsquare.in");
#ifdef _DEBUG
#include "local_helper.cpp"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long
#define int8_t int
void solve() {
  int b;
  fin >> b;
  map<int, char> vals;
  vals[0] = '0';
  vals[1] = '1';
  vals[2] = '2';
  vals[3] = '3';
  vals[4] = '4';
  vals[5] = '5';
  vals[6] = '6';
  vals[7] = '7';
  vals[8] = '8';
  vals[9] = '9';
  vals[10] = 'A';
  vals[11] = 'B';
  vals[12] = 'C';
  vals[13] = 'D';
  vals[14] = 'E';
  vals[15] = 'F';
  vals[16] = 'G';
  vals[17] = 'H';
  vals[18] = 'I';
  vals[19] = 'J';
  auto basebrep = [&] (int n) {
    string s;
    while (n > 0) {
      s += vals[n % b];
      n = n / b;
    }
    reverse(s.begin(), s.end());
    return s;
  };
  auto is_palindrome = [&] (int n) {
    int bas = b;
    string s;
    while (n > 0) {
      s += vals[n % bas];
      n = n / bas;
    }
    reverse(s.begin(), s.end());
    int sz = s.size();
    if (sz == 0)
      return 1;
    for (int i = 0; i <= sz/2; i++) {
      if (s[i] != s[sz - i - 1])
        return 0;
    }
    return 1;
  };
  for (int i = 1; i <= 300; i++) {
    int x = i * i;
    if (is_palindrome(x)) {
      fout << basebrep(i) << " " << basebrep(i * i) << "\n";
    }
  }
}
int main() {
  int tests = 1;
  /* fin >> tests; */
  while (tests--) solve();
  return 0;
}
