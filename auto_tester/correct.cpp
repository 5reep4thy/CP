
#include<bits/stdc++.h>
//#include<chrono>
using namespace std;
#define ll long long
#define int ll
ll mod = 1e9;
void print_stack(stack<int> st) {
  while (st.size() > 0) {
    cout << st.top() << ", ";
    st.pop();
  }
  cout << "\n";
}
ll poww(ll x) {
  ll ans = 1;
  for (int i = 0; i < x; i++) {
    ans *= 2;
    ans %= mod;
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i: a) cin >> i;
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";


}

signed main() {
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
