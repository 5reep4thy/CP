#include<bits/stdc++.h>
using namespace std;

pair<int,int> subarray(vector<int>& arr,int x){
	int left,right;
	left,right=0;
	
	int sum=arr[0];
	while((left<arr.size()&&right<arr.size())){
		// cout<<"\nSum : "<<sum<<" left "<<arr[left]<<" right "<<arr[right];
		if(sum==x)
			return {left,right};
		else if(sum<x){
			right++;
			sum+=arr[right];
		}
		else{sum-=arr[left];
			left++;
			
		}

	}
	return {-1,-1};


}

int main(){vector<int> vec;
	
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	int x=3;
pair<int,int> ans=subarray(vec,x);
cout<<"\nAns : ";
cout<<ans.first<<" "<<ans.second<<"\n";
	return 0;
}