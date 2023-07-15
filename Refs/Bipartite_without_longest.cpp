#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"\n"<<#x<<" : "<<x<<"\n"; 
void debug_vector(vector<int>& a, string s){	
	if(a.size() == 0){
		cout << "\nEmpty vector " << s << "\n";
		return;
	}
	cout << "Vector " << s << "  Size : " << a.size() << "\n";
	cout << "[";
	for(int i = 0; i < a.size() - 1; i++){
		cout << a[i] << ", ";
	}
	cout << a[a.size() - 1];
	cout << "]\n";
}
const int mxN = 2 * 1e5;
vector<int> adj[mxN];
vector<int> col(mxN);
vector<pair<int, int>> edges;
vector<bool> visited(mxN);

void dfs(int u, int colour) {
	visited[u] = 1;
	col[u] = colour;
	for (int v : adj[u]) {
		if (col[u] == 1 && !visited[v]) {
			dfs(v, 2);
		}
		else if (col[u] == 2 && !visited[v]) {
			dfs(v, 1);
		}
		else if (col[u]  == col[v]) {
			cout << "NO\n";
			exit(0);
		}
		else {
			;
		}
	} 
}
void solve() {
	int n, m, v1, v2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		v1--, v2--;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
		edges.push_back(make_pair(v1, v2));
	}

	dfs(1, 1);
	cout << "YES\n";
	for (int i = 0; i < edges.size(); i++) {
		if (col[edges[i].first] == 2)
			cout << "1";
		else 
			cout << "0";
	}
	return;



}

int main(){
	int test = 1;
	freopen("input.txt", "r", stdin);
	// freopen("output.txt","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	while(test--){
		solve();
		
	
	}

	
	



	return 0;
}