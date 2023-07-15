# include<bits/stdc++.h>
using namespace std;

const int mxN = 1 << 15;
int main () {
    int tests = rand() % 10;
    cout << tests << "\n";
    for (int i = 0; i < tests; i++) {
        int n = rand() % mxN;
        cout << n << "\n";
        for (int j = 0; j < n; j++) {
            int ele = rand() % mxN;
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}