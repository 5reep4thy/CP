#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"\n"<<#x<<" : "<<x<<"\n"; 

void debug_vector(vector<int>& a,string s){	
	cout<<"Vector "<<s<<"  Size : "<<a.size()<<"\n";
	cout<<"[";
	for(int i=0;i<a.size()-1;i++){
		cout<<a[i]<<", ";
	}
	cout<<a[a.size()-1];
	cout<<"]\n";
}



class Solution {
public:
	int target2;
	int check=0;

vector<vector<int>> vec;
	vector<int> ans;
	
	int sum_of_vector(vector<int> &arr){
		int sum=0;
		for(int i:arr)
			sum+=i;
		return sum;
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	if(check==0){
    		target2=target;
    		check=1;
    	}

    	
	    	for(int i=0;i<candidates.size();i++){
	    		ans.push_back(candidates[i]);

	   //  		for(int l=0;l<ans.size();l++){
		
				// 	cout<<ans[l]<<" ";
				// }
		
				// cout<<"\n";
	

	    		if(target2==sum_of_vector(ans)){
    				vector<int> temp;
    				int flag=0;
    				for(int p=0;p<ans.size();p++){
    					if(ans[p]>0){
    						if(p>0){
	    						if(ans[p]>=ans[p-1])
	    							temp.push_back(ans[p]);
	    						else{flag=1;
	    							break;
	    						}
    						}
    						else temp.push_back(ans[p]);
    					}
    				}
    				if(flag==0)
    				vec.push_back(temp);

    			}
	    		
	    		if(sum_of_vector(ans)<target2)
	    			combinationSum(candidates,target-sum_of_vector(ans));
	    		
	    			ans.pop_back();
	    	}
	    
	    		
    	return vec;
	}

};



int main(){
	Solution A;
	vector<int> candidates {2,3,6,7};
	int target=7;
	vector<vector<int>> ans=A.combinationSum(candidates,target);
	// debug_vector(ans,"ans");
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}