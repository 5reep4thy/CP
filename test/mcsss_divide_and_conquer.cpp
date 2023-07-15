#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums,int start,int end) {
        
        int maxsum=INT_MIN;
        int currsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(currsum<nums[i]){
                currsum=nums[i];
            }
            if(maxsum<currsum){
                maxsum=currsum;
            }
        }
        return maxsum;
}




int maxxsum(vector<int> &nums,int start,int end){

if(start==end+1){
	int sum=nums[start]+nums[end];
	if(sum>(nums[start]+nums[end])){
		return sum;
	}
	else if(nums[start]>nums[end]){
		return nums[start];

	}
	else
	return nums[end];
}
int mid=(start+end)/2;
int middlesum=0;
int leftsum=maxxsum(nums,start,mid-1);
int rightsum=maxxsum(nums,mid+1,end);
int leftmiddlesum=0,rightmiddlesum=0;
int temp=0;
for(int i=mid-1;i>=start;i--){
	temp+=nums[i];
	if(leftmiddlesum<temp){
		leftmiddlesum=temp;
	}
}
temp=0;
for(int i=mid+1;i<=end;i++){
	temp+=nums[i];
	if(rightmiddlesum<temp){
		rightmiddlesum=temp;
	}
}
middlesum=leftmiddlesum+rightmiddlesum+nums[mid];
if((middlesum>leftsum)&&(middlesum>rightsum))
	return middlesum;
else if((leftsum>middlesum)&&(leftsum>rightsum))
	return leftsum;
else
	return rightsum;

}

int main()
{
vector <int> nums;
nums.push_back(-2);
nums.push_back(1);	
nums.push_back(-3);
nums.push_back(4);
nums.push_back(-1);
nums.push_back(2);
nums.push_back(1);
nums.push_back(-5);
nums.push_back(-4);
cout<<nums.size()<<"\n";
int maxsum=maxSubArray(nums,0,nums.size()-1);


cout<<maxsum;
return 0;
}