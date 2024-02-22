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
ll poww(int a) {
  ll ans = 1;
  for (int i = 0; i < a; i++) {
    ans *= 10;
  }
  return ans;
}
void solve() {
  ll l, r;
  ll ans = 0;
  cin >> l >> r;
  set<ll> ss;
  for (int i = 0; i < 18; i++) {
    for (int j = 0; j < 18; j++) {
      for (int k = 0; k < 18; k++) {
        if (i < j && j < k) {
          for (int d1 = 0; d1 <= 9; d1++) {
            for (int d2 = 0; d2 <= 9; d2++) {
              for (int d3 = 0; d3 <= 9; d3++) {
                if ((d1 * poww(i) + d2 * poww(j) + d3 * poww(k)) >= l && (d1 * poww(i) + d2 * poww(j) + d3 * poww(k)) <= r) {
                  ll val = d1 * poww(i) + d2 * poww(j) + d3 * poww(k);
                  ss.insert(val);
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ss.size() << "\n";

}

int main() {
	//auto start = std::chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> test;
	while(test--) 
		solve();
	//auto stop = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	//float seconds = (float) (duration.count()) / (float) 1e6;
 	//debug(seconds);

	return 0;
}
