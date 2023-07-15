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

class Solution {
public:
    
    int impossible=0;
    void bfs(int source, vector<vector<int>> &adj, vector<int> &colour, int colourofsource) {
        if(colour[source])
            return;
        // debug_vector(colour, "colour");
        colour[source]=colourofsource;
    
        for (int i=0; i<adj.size(); i++) {
        	if(i!=source){
	            if (adj[source][i] == 1 && colour[i]==0) {
	                bfs(i, adj, colour, colourofsource==1?2:1);
	                int temp=colourofsource==1?2:1;
	                // cout << "\nVertex :" << i << " Colour :" << temp;
	            }
	            else if (adj[source][i] ==1 && colour[i] == colourofsource) {
	                impossible = 1;
	                return;
	            }
	        }
            
        }

    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        bool pos=1;
        vector<int> colour(N);
        int m = dislikes.size();
        vector<vector<int>> adj(N,vector<int> (N,0));    
        for (int i=0; i<m; i++) {
            adj[dislikes[i][0]-1][dislikes[i][1]-1] = 1 ;
            adj[dislikes[i][1]-1][dislikes[i][0]-1] = 1;
        }
       
        
        int source = 0;
        int colourofsource=1;
        for(int i=0; i<N; i++){
        	if(colour[i] == 0)
        		// debug_vector(colour, "colour");
        	bfs(i, adj, colour, colourofsource);
        }

        if(impossible ==1 )
            return 0;
        return 1;
        
    }
};

int main() {
	vector<vector<int>> dislikes {{1, 2}, {3, 4}, {4, 5}, {3, 5}};
	int N=5;
	Solution A;
	bool ans= A.possibleBipartition(N, dislikes);
	cout << "\nans : " << ans << "\n";

}