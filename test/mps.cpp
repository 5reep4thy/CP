#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>>sum;
	

	

    int minPathSum(vector<vector<int>>& grid) {
    	
    	
    	sum.resize(grid.size(),vector<int>(grid[0].size(),0));
    	sum[0][0]=grid[0][0];
    	for(int i=1;i<grid.size();i++){
    		
    		sum[i][0]=grid[i][0]+sum[i-1][0];

    	}
    	for(int i=1;i<grid[0].size();i++){
    		
    		sum[0][i]=grid[0][i]+sum[0][i-1];

    	}
    	for(int i=1;i<grid.size();i++){
    		for(int j=1;j<grid[0].size();j++){
    			sum[i][j]=min(sum[i-1][j]+grid[i][j],sum[i][j-1]+grid[i][j]);
    		}
    	}

    	// cout<<"\n";
    	// for(int i=0;i<grid.size();i++){
    	// 	for(int j=0;j<grid[0].size();j++){
    	// 		cout<<grid[i][j]<<" ";
    	// 	}
    	// 	cout<<"\n";
    	// }

    	// cout<<"\n";
    	// for(int i=0;i<grid.size();i++){
    	// 	for(int j=0;j<grid[0].size();j++){
    	// 		cout<<sum[i][j]<<" ";
    	// 	}
    	// 	cout<<"\n";
    	// }

    	return sum[grid.size()-1][grid[0].size()-1];
        
    }
};

int main(){

	Solution A;
	vector<vector<int> > grid;
	vector<int> test{1,2,5};
	grid.push_back(test);
	test={3,2,1};
	grid.push_back(test);
	// test={4,2,1};
	// grid.push_back(test);
	int ans=A.minPathSum(grid);
	cout<<ans<<"\n";





	return 0;
}