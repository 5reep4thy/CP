#include<bits/stdc++.h>
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



vector<pair<int, int> > pt;
vector<int> a, dp, p, t;

void solve() {

	
	int n;
	cin >> n;

	a.resize(n);
	dp.resize(n + 1);
	p.resize(n + 1);
	pt.resize(n);
	t.resize(n);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pt[i].first = a[i];
		pt[i].second = i;
	}
	
	sort(a.begin(), a.end());
	sort(pt.begin(), pt.end());
	for(int i = 1; i <= n; i++) {
		dp[i] = 1e9;
		p[i] = -1;
	}
	dp[0] = 0;
	
	
	for(int i = 0; i < n; i++)
		for(int j = 3; j <= 5 && i + j <= n; j++) {
			if(dp[i + j] > (dp[i] + a[i + j - 1] - a[i])) {
				dp[i + j] = dp[i] + a[i + j - 1] - a[i];
				p[i + j] = i;
			}
			
			
		}
	
	int cur = n;
	int cnt = 1;
	// debug(dp);
	// debug(p);
	// debug(a);
	// debug(pt);
	
	
	while(cur > 0) {
		for (int i = cur; i > p[cur]; i--) {
			t[pt[i - 1].second] = cnt;
		}
		cnt++;
		cur = p[cur];
	}

	cout << dp[n] << " " << cnt - 1 << "\n";
	for (int i = 0; i < n; i++)
		cout << t[i] << " ";
	cout << "\n";



}

int main() {
	
	int test = 1;
	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	#endif
	
	while(test--) 
		solve();


	return 0;
}