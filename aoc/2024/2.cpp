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
	int ans = 0;
	while (getline(inp, s)) {
		vector<int> a;
		std::istringstream ss(s);
		int x;
		while (ss >> x) {
			a.push_back(x);
		}
		for (size_t j = 0; j < a.size(); j++) {
			vector<int> b = a;
			b.erase(b.begin() + j);
			vector<int> bb(b);
			sort(bb.begin(), bb.end());
			bool is_fine = 0;
			if (b == bb) {
				is_fine = 1;
			}
			sort(bb.begin(), bb.end(), [] (int xx, int yy) { return xx > yy;});
			if (bb == b) {
				is_fine = 1;
			}
			// debug(is_fine);
			if (!is_fine)
				continue;
			bool problem = 0;
			for (size_t i = 1; i < bb.size(); i++) {
				if (abs(bb[i] - bb[i - 1]) > 3 || abs(bb[i] - bb[i - 1]) < 1) {
					problem = 1;
					break;
				}
			}
			if (!problem) {
				ans++;
				break;
			}
		}
	}
	cout << ans << "\n";
	
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
