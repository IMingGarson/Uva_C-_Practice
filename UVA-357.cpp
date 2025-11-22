#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<int> coins = {1, 5, 10, 25, 50};
    long long m;
    while (cin >> m) {
        vector<long long> f(m + 1, 0);
        f[0] = 1;
        for (int coin: coins) {
            for (int i=coin; i<=m; i++) {
                f[i] += f[i - coin];
            }
        }
        if (f[m] == 1) {
            cout << "There is only " << f[m] << " way to produce " << m << " cents change.";
        } else {
            cout << "There are " << f[m] << " ways to produce " << m << " cents change.";
        }
        nl;
    }

    return 0;
}
