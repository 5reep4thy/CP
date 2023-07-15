#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.length(),size2=text2.length();

        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=0;i<=size1;i++){
        	for(int j=0;j<=size2;j++){
        		if(i==0||j==0)
        			dp[i][j]=0;
        		else if(text1[i-1]==text2[j-1])
        			dp[i][j]=1+dp[i-1][j-1];
        		else
        			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        	}
        }

        return dp[size1][size2];
    }
};

int main(){
	Solution A;
	string text1="abc",text2="bc";
	int ans=A.longestCommonSubsequence(text1,text2);
	cout<<"\n"<<ans<<"\n";





	return 0;
}