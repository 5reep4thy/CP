#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cout<<"\n"<<#x<<" : "<<x<<"\n"; 
void debug_vector(vector<int>& a,string s){	
	if(a.size()==0){
		cout<<"\nEmpty vector "<<s<<"\n";
		return;
	}
	cout<<"Vector "<<s<<"  Size : "<<a.size()<<"\n";
	cout<<"[";
	for(int i=0;i<a.size()-1;i++){
		cout<<a[i]<<", ";
	}
	cout<<a[a.size()-1];
	cout<<"]\n";
}
int mod = 1e9 + 7;
int binexp(int a, int exp) {
	// exp = a;
	int ans = 1;
	while(exp) {
		if (exp & 1) {
			ans = ans * a;
			ans = ans % mod;
		}
		a = a * a;
		a = a % mod;
		exp = exp >> 1;
	}
	return ans % mod;
}

int fact (int a) {
	int ans = 1;
	for (int i = 1; i <= a; i++) {
		ans = ans * i;
		ans = ans % mod;
	}
	return ans % mod;
}
void solve() {
	int n, m;
	cin >> n >> m;
	// compute (n + 2m - 1)! / (2m)! (n - 1)!
	int temp = fact(2 * m) * fact(n - 1);
	temp = temp % mod;
	int temp1 = fact(n + 2 * m - 1);
	temp1 = temp1 % mod;
	cout << (temp1 * (binexp(temp, mod - 2) % mod)) % mod << "\n";
	

}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	#endif
	// freopen("output.txt", "w", stdout);
	while(test--) 
		solve();


	return 0;
}