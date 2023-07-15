#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:

		int binarySearch(vector<int> &arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 


		int search(vector<int>& nums, int target) {
			if(nums.size()<1000){
				auto it=find(nums.begin(),nums.end(),target);
				if(it==nums.end())
					return -1;
				else{
					return distance(nums.begin(),it);
				}
			}
			int start=0;
			int count=1;
			int prev=0;
			while(nums[start]<nums[start+1]){
				prev=start;
				start=start+count;
				count*=2;
				if(nums[start]<nums[0]){
					start=prev;
					count=1;
				}
			}
			cout<<"\nstart : "<<start<<"\n";

			int left=binarySearch(nums,0,start,target);
			int right=binarySearch(nums,start+1,nums.size()-1,target);
			if(left==-1&&right==-1)
				return -1;
			else if(left!=-1)
				return  left;
			else 
				return right;
		}

};

int main(){
	Solution A;
	vector<int> temp{57,58,59,62,63,66,68,72,73,74,75,76,77,78,80,81,86,95,96,97,98,100,101,102,103,110,119,120,121,123,125,126,127,132,136,144,145,148,149,151,152,160,161,163,166,168,169,170,173,174,175,178,182,188,189,192,193,196,198,199,200,201,202,212,218,219,220,224,225,229,231,232,234,237,238,242,248,249,250,252,253,254,255,257,260,266,268,270,273,276,280,281,283,288,290,291,292,294,295,298,299,4,10,13,15,16,17,18,20,22,25,26,27,30,31,34,38,39,40,47,53,54};
	int target=30;
	int ans=A.search(temp,target);
	cout<<"\n"<<ans<<"\n";


	return 0;
}