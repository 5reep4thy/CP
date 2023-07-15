#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> buildmaxheap(vector<int>& stones){
		vector <int> heap=stones;
		make_heap(heap.begin(),heap.end());
		return heap;
		
	} 
    int lastStoneWeight(vector<int>& stones) {
    
    	vector<int> heap=buildmaxheap(stones);
    	
    	while(heap.size()>1){
    		int max1=heap.front();
    		pop_heap(heap.begin(),heap.end());
    		heap.pop_back();
    		
    		int max2=heap.front();
    		pop_heap(heap.begin(),heap.end());
    		heap.pop_back();

    		if(max1!=max2){
    			heap.push_back(abs(max1-max2));
    			push_heap(heap.begin(),heap.end());
    		}    			
    	
    	}


    	if(heap.size()==1)
    		return heap[0];
   		else
    		return 0;

    }
};

int main(){
	Solution A;
	vector<int> stones;
	
	stones.push_back(2);
	stones.push_back(2);
	

	int ans=A.lastStoneWeight(stones);
	cout<<"\n ans :"<<ans;
	
}