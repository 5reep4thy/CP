#include<bits/stdc++.h>
//#include<chrono>
using namespace std;
#ifndef ONLINE_JUDGE
#include "local_helper.cpp"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long 

class Solution {
public:
    int get(int ind) {
      if (ind % 2 == 0) {
        return -ind;
      }
      return ind;
    }
    long long maximumStrength(vector<int>& nums, int k) {
      int n = nums.size();
      reverse(nums.begin(), nums.end());
      vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2)));
      dp[0][1][1] = nums[0]; 
      for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
          dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
          dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1]);
          dp[i][j][1] = max(dp[i][j][1], get(j) * nums[i] + dp[i - 1][j - 1][0]);
          dp[i][j][1] = max(dp[i][j][1], get(j) * nums[i] + dp[i - 1][j - 1][1]);
          dp[i][j][1] = max(dp[i][j][1], get(j) * nums[i] + dp[i - 1][j][1]);
        }
      }
      return max(dp[n - 1][k][0], dp[n - 1][k][1]);
    }
};
void solve() {
    Solution A;
    vector<int> nums{1, 2, 3, -1, 2};
    cout << A.maximumStrength(nums,3);
}

int main() {
	//auto start = std::chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	//cin >> test;
	while(test--) 
		solve();
	//auto stop = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	//float seconds = (float) (duration.count()) / (float) 1e6;
 	//debug(seconds);

	return 0;
}
