#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int check(vector<vector<char>> & matrix,int row,int col,int s){
		int flag1=1,flag2=1;
		for(int i=row;i<row+s;i++){

			if(matrix[i][col+s-1]=='0'){
				flag1=0;
				break;
			}
		}
		// cout<<"adad"<<"\n";
		for(int j=col;j<col+s;j++){
			if(matrix[row+s-1][j]=='0'){
				flag2=0;
				break;
			}
		}
		if(flag1==1&&flag2==1)
			return 1;
		return 0;

	}
    int maximalSquare(vector<vector<char>>& matrix) {
    	if(matrix.size()==0)
    		return 0;
    	vector<vector<int>> dp;
    	int maxsquarearea=matrix[0][0];
    	int row=matrix.size();
    	int col=matrix[0].size();
    	dp.resize(matrix.size(),vector<int>(matrix[0].size(),0));
    	
    	for(int i=0;i<row;i++){
    		for(int j=0;j<col;j++){

    			if(matrix[i][j]=='1'){
    				dp[i][j]=1;
    			
    			}
    		}
    	}
    	


    	int possible;
    	int maxi=0;
    	for(int i=0;i<row;i++)
    		for(int j=0;j<col;j++)
    			if(matrix[i][j]=='1')
    				maxi=1;
    	if(maxi==0)
    		return 0;
    	for(int s=2;s<=row+col-(max(row,col));s++){
    		
    		for(int i=0;i<row-s+1;i++){
    			for(int j=0;j<col-s+1;j++){
	    			if(dp[i][j]==(s-1)){
	    				possible=check(matrix,i,j,s);
	    				if(possible){
	    					dp[i][j]=s;
	    					maxi=s;

	    				}
	    			}
	    			
	    		}
	    	}
	    }
	    for(int i=0;i<row;i++){
    		for(int j=0;j<col;j++)
    			cout<<dp[i][j]<<" ";
    		cout<<"\n";
    	}
	    
	    



    	return maxi*maxi;    
    }
};

int main(){
	freopen("input.txt","r",stdin);
	int row,col;
	cin>>row>>col;
	vector<vector<char>> square(row,vector<char>(col,'0'));
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>square[i][j];

	Solution A;
	int ans=A.maximalSquare(square);
	cout<<ans<<"\n";




	return 0;
}