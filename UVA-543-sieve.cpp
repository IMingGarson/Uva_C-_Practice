#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MAX = 1000000;
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i*i<=MAX; i++) {
        if (is_prime[i] && i * i < MAX) {
            for (int j=i*i; j<=MAX; j+=i) {
                is_prime[j] = false;
            }
        }
    }

    int n;
    while (cin >> n && n > 0) {
        for (int i=2; i<n; i++) {
            if (is_prime[i] && is_prime[n - i]) {
                cout << n << " = " << i << " + " << n - i;
                nl;
                break;
            }
        }
    }

    return 0;
}
