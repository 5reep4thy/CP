#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void swap(int *a,int *b){
		int temp=*a;
		*a=*b;
		*b=temp;
	}
	int partition(vector<int> &arr,int l,int r){
		int a=arr[l];
		int b=l;
		l++;
		// printv(arr);
		while(l<r){
			
			while(arr[l]<a&&(l<r))
				l++;
			while(arr[r]>a&&(l<r))
				r--;
			
			swap(&arr[l],&arr[r]);
			// printv(arr);
			cout<<"\t"<<arr[l]<<" "<<arr[r]<<"\n";

		}
		
		swap(&arr[r],&arr[b]);
		
		return r;

	}
	int kthsmallest(vector<int>& arr,int l,int r,int k){
		int index=partition(arr,l,r);
		// printv(arr);
		if(index==k){
			return arr[k];
		}
		if(index>k){
			return kthsmallest(arr,l,index-1,k);
		}
		else
			return kthsmallest(arr,index+1,r,k-index);
	}
	void printv(vector<int>& a){
		for(int i:a)
			cout<<i<<" ";
		cout<<"\n";
	}
};
int main(){
	Solution A;
	int k=5;
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	

	int x=A.kthsmallest(nums,0,nums.size()-1,k);
	// int x=A.partition(nums,0,nums.size()-1);
	// A.printv(nums);
		cout<<"adasd "<<x<<"\n";


	return 0;
}