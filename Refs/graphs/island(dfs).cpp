#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void changevisited(vector<vector<char>>& grid,int i,int j){
		if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||visited[i][j]==1||grid[i][j]=='0')
			return;
		visited[i][j]=1;
		changevisited(grid,i-1,j);
		changevisited(grid,i+1,j);
		changevisited(grid,i,j-1);
		changevisited(grid,i,j+1);

	}
	vector<vector<int>> visited;
    int numIslands(vector<vector<char>>& grid) {
    	int ans=0;
    	if(grid.size()==0)
    		return 0;
    	vector<int> a(grid[0].size(),0);
    	visited.resize(grid.size(),a);
    	for(int i=0;i<grid.size();i++){
    		for(int j=0;j<grid[i].size();j++){
    			if(grid[i][j]=='1'&&visited[i][j]==0){
    				changevisited(grid,i,j);
    				ans++;
    			}
    		}
    	}

        
    return ans;
    }
};

int main(){
	Solution A;
	vector<vector<char> > grid;
	vector<char> g{'1','1','0','0','0'};
	grid.push_back(g);
	g={'1','1','0','0','0'};
	grid.push_back(g);
	g={'0','0','1','0','0'};
	grid.push_back(g);
	g={'0','0','0','1','1'};
	grid.push_back(g);
	int ans=A.numIslands(grid);
	cout<<"\n"<<ans<<"\n";

	return 0;
}