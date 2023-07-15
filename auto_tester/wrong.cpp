#include<bits/stdc++.h>
//#include<chrono>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long
vector<int> pals;
const int mxN = 1 << 20;
bool is_pal(int x) {
    string s = to_string(x);
    string temp = s;
    reverse(temp.begin(), temp.end());
    if (temp == s)
    return 1;
    return 0;
}
void init() {
    for (int i = 0; i < mxN; i++) {
        if (is_pal(i)) 
            pals.push_back(i);
    }
}
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    vector<int> cc(mxN, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ++cc[a[i]];
    
        for (int j = 0; j < pals.size(); j++) {
            ans += cc[a[i] ^ pals[j]];
        }
    }
    cout << ans << "\n";
}

int main() {
	//auto start = std::chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
    init();
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
