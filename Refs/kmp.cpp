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

void solve() {
  string s  ="isisa#thisisatest";
  int n = s.size();
  vector<int> k (n);
  k[0] = 0;
  if (s[1] == s[0])
    k[1] = 1;
  for (int i = 2; i < n; i++) {
    int j = k[i -1];
   while (j > 0 && s[i] != s[j] ) {
     j = k[j - 1];
   }
   if (s[j] == s[i])
     k[i] = j + 1;
   else
     k[i] = 0;
  }
  debug(k);



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
