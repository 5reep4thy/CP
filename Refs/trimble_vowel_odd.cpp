#include<bits/stdc++.h>
using namespace std;

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

bool isvowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}
void solve() {
	int n;
	cin >> n;
	vector<char> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	vector<int> dpe(n);
	vector<int> dpo(n);
	dpe[0] = 0;
	dpo[0] = 1;
	for (int i = 1; i < n; i++) {
		if (isvowel(a[i])) {
			dpe[i] = dpo[i-1] + dpe[i-1];
			dpo[i] = dpo[i-1] + dpe[i-1] + 1;
		}
		else {
			dpo[i] =  dpo[i-1] + dpe[i-1] + 1;
			dpe[i] = dpe[i-1];
		}
	}
	cout << dpo[n-1] + dpe[n-1] << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> test;
	while(test--) 
		solve();


	return 0;
}