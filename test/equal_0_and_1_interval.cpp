#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"\n"<<#x<<" : "<<x<<"\n"; 
void debug_vector(vector<int>& a,string s){	
	if(a.size()==0){
		cout<<"\nEmpty vector "<<s<<"\n";
		return;
	}
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
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> pref(n+1, 0);
        unordered_map <int, int> first;
        unordered_map <int, int> first_found;
        pref[0] = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == 0)
                pref[i+1] = pref[i]-1;
            else
                pref[i+1] = pref[i]+1;
            
        }
        debug_vector(nums, "nums");
        debug_vector(pref, "pref");
        first[0]=0;
        first_found[0]=1;
        for (int i = 1; i<=n; i++) {
            if (first_found[pref[i]] ==1)
                ans=max(ans, i-first[pref[i]]);
            else {
                first_found[pref[i]]=1;
                first[pref[i]]=i;
                
            }
            
        }
        return ans;
    }
};

int main() {
Solution A;
vector<int> s {1, 0, 0, 0};
int ans = A.findMaxLength(s);
cout << ans << "\n";

	return 0;
}