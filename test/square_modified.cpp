#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        vector<vector<int>> dp;
        int row = matrix.size();
        int col = matrix[0].size();
        dp.resize(row,vector<int> (col,0));
        
        for (int i=0;i<row;i++){
            for (int j=0; j<col; j++){
                if(matrix[i][j]==1){
                    if(i==0||j==0)
                        dp[i][j]=1;
                    else
                        dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+1);
                }
                else
                    dp[i][j]=0;
                ans+=dp[i][j];
                 
            }
        }
    return ans;
    }
};

int main(){
	Solution A;
	vector<vector<int>> matrix {{0}};
	int ans=A.countSquares(matrix);
	cout<<ans;

	return 0;
}