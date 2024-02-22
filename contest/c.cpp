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

void solve() {
  int n;
  cin >> n;
  int tmp = n;
  if (n == 0) {
    cout << 0 << "\n";
    return;
  }
  int i = 31;
  int fl = 0, ind = 31;
  while (tmp > 0 && i >= 0) {
    if ((1 << i) & tmp) {
      fl = 1;
      ind = i;
    }
    if (fl == 1) {
      while ((1 << i) & tmp && i >= 0)
        i--;
      i++;
      ind = i;
      break;
    }
    i--;
  }
  int ans = 0;
  int l = ind - 1;
  int yup = 0;
  for (int i = ind - 1;i >= 0; i--) {
    if (((1 << i) & n) == 0) {
      continue;
    }
    else {
      yup = 1;
    }
  }
  if (yup == 0) {
    cout << "0\n";
    return;
  }
  int tgt = 0;
  for (int i = 31; i >= ind; i--) {
    if ((1 << i) & n)
      tgt += (1 << i);
  }
  tgt += (1 << (ind -1));
  cout << tgt - n  << "\n";



}

int main() {
	//auto start = std::chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> test;
	while(test--) 
		solve();
	//auto stop = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	//float seconds = (float) (duration.count()) / (float) 1e6;
 	//debug(seconds);

	return 0;
}
