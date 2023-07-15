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

int par[110000];

int return_parent(int x) {
	if (par[x] == x)
		return x;
	
	return return_parent(par[x]);

}

void solve() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		par[i] = i;
	int temp1, temp2, par1, par2;
	for (int i = 1; i <= k; i++) {
		
		cin >> temp1 >> temp2;
		par1 = return_parent(temp1);
		par2 = return_parent(temp2);
		
		if (par1 != par2) {
			if (par1 > par2)
			swap(par1, par2);
			par[par2] = par1;
		}
		
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
		if (par[i] == i)
			count++;
// connected components = count
	




}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	#endif
	while(test--) 
		solve();


	return 0;
}