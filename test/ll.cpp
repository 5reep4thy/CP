#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n; vector<int> t;
    void update(int x) {
        for (; x <= n + 1; x += x&-x) t[x]++;
    }
    int get(int x) {
        int res = 0;
        for (; x; x -= x&-x) res += t[x];
        return res;
    }
    int countRangeSum(vector<int>& num, int L, int R) {
        n = num.size();
        vector<long long> s(n+1); s[0] = 0;
        for (int i=1; i<=n; ++i) s[i] = s[i-1] + num[i-1];
        sort(s.begin(), s.end()); 
    cout<<"\n";
    for(auto i:s)
    	cout<<i<<" ";
    auto it=unique(s.begin(), s.end());
    cout<<"\n";
    for(auto i:s)
    	cout<<i<<" ";
    cout<<"\nnnn "<<int(it-s.begin())<<" "<<s.end()-s.begin()<<"\n";
        s.resize(it - s.begin());
         cout<<"\n";
    for(auto i:s)
    	cout<<i<<" ";
    

        
        t.clear(); t.resize(n+2);
        long long sum = 0; int ans = 0;
        int pos = lower_bound(s.begin(), s.end(), 0) - s.begin() + 1;
        cout<<"\npos :"<<pos;
        update(pos);
        cout<<"\nt ";
    for(auto i:t)
    	cout<<i<<" ";
        for (int i=0; i<n; ++i){
            sum += num[i];
            int pos1 = upper_bound(s.begin(), s.end(), sum - L) - s.begin();
            int pos2 = lower_bound(s.begin(), s.end(), sum - R) - s.begin();
            ans += get(pos1) - get(pos2);
            pos = lower_bound(s.begin(), s.end(), sum) - s.begin() + 1;
            update(pos);
        }
        return ans;
    }
};

int main(){
	Solution A;
	vector<int> num={-1,5,2,3,-3,-4,7,6};
	int x=A.countRangeSum(num,-1,6);
	cout<<"\n"<<x;

	return 0;
} 