#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
    	vector<int> dp(nums.size(),0);
    	dp[0]=1;
    	for(int i=1;i<dp.size();i++){
    		for(int j=i-1;j>=0;j--){
    			if((dp[j]==1)&&(nums[j]>=(i-j))){
    				dp[i]=1;
    				break;	
    			}
    		}
    	}
    	return dp[dp.size()-1];

        
    }
};

int main(){
	Solution A;
	vector<int> nums {3,2,1,0,4};
	bool ans=A.canJump(nums);
	cout<<"\n"<<ans;



	return 0;
}