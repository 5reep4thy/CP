#include<bits/stdc++.h>
//#include<chrono>
#include <boost/algorithm/string.hpp>
using namespace std;

#ifdef _DEBUG
#include "local_helper.cpp"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve() {
	ifstream inp;
	inp.open("input.txt", std::ios_base::in );
	string s;
	vector<int> a, b;
	map<int, int> cnt;
	while (getline(inp, s)) {
		std::istringstream ss(s);
		int x, y;
		ss >> x >> y;
		a.push_back(x);
		cnt[y]++;
		b.push_back(y);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans += a[i] * cnt[a[i]];
	}
	debug(ans);
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
