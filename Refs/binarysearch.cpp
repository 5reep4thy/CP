#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> & arr,int left,int right,int x){
	while(left<=right){
		int mid=(left+right)/2;
		if(arr[mid]==x)
			return mid;
		else if(arr[mid]<x)
			left=mid+1;
		else
			right=mid-1;
	}
	return -1;
}

int main(){
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(8);
	arr.push_back(10);
	arr.push_back(12);
	arr.push_back(22);

	int x=binarysearch(arr,0,arr.size()-1,21);
	cout<<x<<"\n";



	return 0;
}