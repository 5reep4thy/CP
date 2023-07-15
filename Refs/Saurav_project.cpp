/*
I/P
12
4
a	1	0.2	0	0	0	0
b	2	0.4	0	0	0	0
c	3	0.7	1	0	0	0
d	4	0.1	1	2	0	0
e	5	0.3	2	0	0	0
f	6	0.11	3	0	0	0
g	7	0.32	3	0	0	0
h	8	0.6	3	4	0	0
i	9	0.27	6	7	8	0
j	10	0.38	5	8	0	0
k	11	0.5	9	10	0	0
l	12	0.12	11	0	0	0

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<"\n"<<#x<<" : "<<x<<"\n"; 
void debug_vector(vector<int>& a, string s){	
	if(a.size() == 0){
		cout << "\nEmpty vector " << s << "\n";
		return;
	}
	cout << "group " << s << "\n";
	cout << "[";
	for(int i = 0; i < a.size() - 1; i++){
		cout << a[i] << ", ";
	}
	cout << a[a.size() - 1];
	cout << "]\n";
}
void debug_vector1(vector<float>& a, string s){	
	if(a.size() == 0){
		cout << "\nEmpty vector " << s << "\n";
		return;
	}
	cout << "group " << s << "\n";
	cout << "[";
	for(int i = 0; i < a.size() - 1; i++){
		cout << a[i] << ", ";
	}
	cout << a[a.size() - 1];
	cout << "]\n";
}

vector<int> adj[13];
vector<float> cost;
vector<float> timef(13);
vector<bool> visited(13, 0);
vector<pair<float, int>> pp;
vector<int> inps(13);

bool sortinrev(const pair<float,int> &a, const pair<float,int> &b) 
{ 
       return (a.first > b.first); 
} 

void dfs(int u, int point) {
	
	for (int v : adj[u] ) {
		if (!visited[v]){
			visited[v] = 1;
			cost[point] = cost[point] + timef[v];
			// cout << "Visited " << v << "\n";
			dfs(v, point);

		}
	}
	

}



int main(){
	
	freopen("input.txt", "r", stdin);
	// freopen("output.txt","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, outno;
	cin >> n >> outno;
	cost.resize(n + 1);
	timef.resize(n + 1);
	
	
	for (int i = 1; i <= n; i++) {
		char ch;
		int temp;
		cin >> ch;
		cin >> temp;
		cin >> timef[i];
		for (int j = 0; j < outno; j++) {
			cin >> temp;
			if (temp == 0)
				continue;
			adj[temp].push_back(i);
			inps[i]++;
		}

	}


			vector<float> end = timef;
		// debug_vector1(end, "end");

	for (int i = 1; i <= n; i++) {
		for (int j : adj[i]) 
			cout << j << " ";
		cout << "\n";
	} 
	
	for (int i = 1; i <= n; i++) {
		dfs(i, i);
		cost[i] = cost[i] + timef[i];
		cout << "\n";
		for (int i = 0; i <= n; i++)
			visited[i] = 0;
	}


	cout << "Cost" << "\n";
	for (int i = 1; i <= n; i++) 
		cout << cost[i] << "\n";
	
	for (int i = 1; i <= n; i++) {
		
		pp.push_back(make_pair(cost[i], i));
		
	}



	sort(pp.begin(), pp.end(), sortinrev);

	cout << "\n After sorting\n";
	for (int i = 0; i < n; i++) {
		cout << pp[i].first << " " << pp[i].second << "\n";
	}

	// debug_vector(inps, "inps");
	vector<pair<float, int>> temp (pp.begin(), pp.begin() + n);
	pp = temp;


	// cout << "\n Hello\n ";
	int set_no = 1;

	
	while (pp.size() > 0) {
		vector<int> cur;
		float balance = 1.0;
		 
			for (int i = 0; i < pp.size(); i++) {
				if (inps[pp[i].second] == 0 && timef[pp[i].second] < balance) {
					// cout << pp[i].second << " pushed back" << "\n";
					cur.push_back(pp[i].second);
					for (int v : adj[pp[i].second]) {
						inps[v]--;
					}
					balance = balance - timef[pp[i].second];
					pp.erase(pp.begin() + i);
					i--;

				}

			}
		string message = " no " + to_string(set_no++);
		debug_vector(cur, message);
		float g = 0;
		
		for (int j = 0; j < cur.size(); j++) {
			g+=end[cur[j]];
		}
		message = "with time " + to_string(g);
		cout << message << "\n";
	}
	return 0;
}

