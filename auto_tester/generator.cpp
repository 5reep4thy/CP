# include<bits/stdc++.h>
#include <random>
using namespace std;

const int mxN = 20;
int main () {
    int tests = rand() % mxN;
    cout << tests << "\n";
    for (int i = 0; i < tests; i++) {
        int n, m;
        n = rand() % mxN;
        m = rand() % mxN;
        cout << n << " " << m << "\n";
        cout << "\n";
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
          a[i] = i + 1;
        }
        auto rng = default_random_engine {};
        shuffle(a.begin(), a.end(), rng);
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";

    }

    return 0;
}
