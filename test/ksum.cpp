#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n=nums.size();
        int res=0,sum=0;
        map[0]=1;
        for(int i=0;i<n;i++){
        	sum+=nums[i];
        	if(map[sum-k]>0)
        		res+=map[sum-k];
        	map[sum]++;
        }
    return res;
    }
    
};

int main(){
	Solution A;
	vector<int> v{1,1,1};
	int k=2;
	cout<<"Ans "<<A.subarraySum(v,k);

	


	return 0;
}