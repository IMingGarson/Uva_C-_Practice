// Combination
#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

long long C(int n, int r) {
    if (n - r < r) r = n - r; 
    long long product = 1;
    for (int i = 1; i <= r; i++)
    {
        product = product * (n - r + i) / i;
    }
    return product;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        cout << n << " things taken " << m << " at a time is " << C(n, m) << " exactly."; nl;
    }
    return 0;
}
