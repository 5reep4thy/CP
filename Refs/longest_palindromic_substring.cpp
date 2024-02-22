#include<bits/stdc++.h>
//#include<chrono>
using namespace std;
#ifndef ONLINE_JUDGE
#include "local_helper.cpp"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long
vector<int> palindrome_cal(const string& s) {
  string t;
  t += '#';
  for (int i = 0; i < (int) s.size(); i++) {
    t += s[i];
    t += '#';
  }
  debug(t);
  int n = t.size();
  vector<int> llp(n, 0);
  int l = 0, r = 0, c = 0;
  int i = 0;
  while (i < n) {
    llp[i] = min(llp[c - (i - c)], r - i);
    int le = i - llp[i] - 1;
    int ri = i + llp[i] + 1;
    while (le >= 0 && ri < n) {
      if (t[le] == t[ri]) {
        llp[i]++;
        le--, ri++;
      }
      else 
        break;
    }
    if (ri > r) {
      r = ri;
      l = le;
      c = i;
    }
    i++;
  }
  return llp;
}
void solve() {
  string s = "abacabacabb";
  /* s = "abccbd"; */
  vector<int> pal =  palindrome_cal(s);
  debug(pal);
}

int main() {
	//auto start = std::chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	while(test--) 
		solve();
	//auto stop = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	//float seconds = (float) (duration.count()) / (float) 1e6;
 	//debug(seconds);

	return 0;
}
