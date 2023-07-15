#include<bits/stdc++.h>
using namespace std;
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
	
	

    vector<int> findAnagrams(string s, string p) {
        int n=s.length();
        int m=p.length();

        vector<int> window_freq(26);
		vector<int> window_f(26);
        vector<int> ans;
        if(n==0)
        	return ans;
        for(char c:p){
        	window_f[c-'a']++;
        }
        for(int i=0;i<m;i++){
        	window_freq[s[i]-'a']++;
        }
        if(window_freq==window_f)
        	ans.push_back(0);
        int i=1;
        int j=1+m;
        while(i+m<=n+1){
        	// debug_vector(window_freq,"window_freq");
        	window_freq[(int) (s[i-1]-'a')]--;
        	window_freq[(int) (s[j-1]-'a')]++;
        	if(window_freq==window_f)
        	ans.push_back(i);
        i++;j++;

        }
      	return ans;
    }
};

int main(){
	Solution A;
	string s="cbaebabacd";
	string p="abc";
	vector<int> ans=A.findAnagrams(s,p);
	debug_vector(ans,"ans");


	return 0;
}