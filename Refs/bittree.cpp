#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> bittree;
	// bittree.push_back(1);

	int divide(int dividend, int divisor) { 
  
 
	  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; 
	  
	  // Update both divisor and 
	  // dividend positive 
	  dividend = abs(dividend); 
	  divisor = abs(divisor); 
	  
	  // Initialize the quotient 
	  int quotient = 0; 
	  while (dividend >= divisor) { 
	    dividend -= divisor; 
	    ++quotient; 
    } 
  
  return sign * quotient; 
}

	int getproduct(int index){
		int ans=1;
		index++;
		while(index>0){

			ans*=bittree[index];
			index-=index&(-index);

		}
		return ans;
	}

	void updatebittree(int n,int index,int val){
		index++;
		while(index<=n){
			bittree[index]*=val;
			index+=index&(-index);

		}
	}

	void constructbittree(vector<int>& nums){
		int n=nums.size();
		for(int i=0;i<=n;i++){
			bittree.push_back(1);
		}
		for(int i=0;i<n;i++){
			updatebittree(n,i,nums[i]);
		}

	}
	

    vector<int> productExceptSelf(vector<int>& nums) {
    	vector<int> ans(nums.size(),0);
    	int n=nums.size();
    	// constructbittree(nums);
    	// int totl=getproduct(nums.size()-1);
    	
    	// int flag=0;
    	// for(int i=0;i<n;i++){
    	// 	if(nums[i]==0)
    	// 		flag=1;
    	// }
    	if(count(nums.begin(),nums.end(),0)>=2){
    		for(int i=0;i<n;i++){
    			ans[i]=0;
    		}
    		return ans;
    	}
    	// ans[0]=divide(totl,nums[0]);
    	// for(int i=1;i<n;i++){
    	// 	ans[i]=getproduct(i-1)*divide(totl,getproduct(i));

    	// }
    	int productwithout0=1;
    	for(int i=0;i<n;i++){
    		if(nums[i]!=0)
    			productwithout0*=nums[i];
    	}

    	if(count(nums.begin(),nums.end(),0)==1){
    		for(int i=0;i<n;i++){
    		if(nums[i]!=0)
    			ans[i]=0;
    		else
    			ans[i]=productwithout0;
    		}
    	return ans;
    	}
    	
    	for(int i=0;i<n;i++){
    		ans[i]=productwithout0/nums[i];
    	}

        
    
    return ans;
    }
};

int main(){
	Solution A;

	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	vector<int> b=A.productExceptSelf(nums);cout<<"\n";
	for(int i=0;i<b.size();i++){
		cout<<b[i]<<" ";
	}




	return 0;
}