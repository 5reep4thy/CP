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
template <typename T>
vector <T> Head(vector <T>& v, size_t top) {
    return {
        v.begin (),
        next(v.begin (), min(top , v.size ()))
    };
}
void solve() {
  vector <int> v = {1, 2, 3, 4, 5};
    for (int &x : Head(v, 3)) {
        ++x; //increasing each element by 1 
        debug(x);
    }
    for (int x : v) {
        cout << x << " ";
    }
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
