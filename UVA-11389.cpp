// Greedy is enough
#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d, r;
    while (cin >> n >> d >> r, n, d, r) {
        int res = 0;
        vector<int> morning(n), evening(n);
        for (int i=0; i<n; i++) {
            cin >> morning[i];
        }
        for (int i=0; i<n; i++) {
            cin >> evening[i];
        }
        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end(), greater<int>());
        for (int i=0; i<n; i++) {
            int t = morning[i] + evening[i];
            if (t > d) {
                int pay = (t - d) * r;
                res += pay;
            }
        }
        cout << res; nl;
    }
    return 0;
}
