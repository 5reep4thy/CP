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
struct node {
	int f, s;
};
vector<int> A {4, 6, 1, 3, 9, 7, 8};
vector<int> B {1, 2, 3, 4, 5, 6, 7};

vector<node> v;

bool op (node &a, node &b) {
	
	return a.f < b.f;
}
void solve() {
	node temp;
	for (int i = 0; i < A.size(); i++) {
		temp.f = A[i];
		temp.s = B[i];
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), op);
	for (int i = 0; i < A.size(); i++) {
		A[i] = v[i].f;
		B[i] = v[i].s;
	}
	debug_vector(A, "A");
	debug_vector(B, "B");


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	while(test--) 
		solve();


	return 0;
}