#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

const int SHIFT = 5000;
const int LIM = 10000;
bool dp[51][LIM + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    while (cin >> N >> M) {
        vector<int> sets;
        int tot = 0;
        for (int i=0; i<N+M; i++) {
            int a; cin >> a;
            sets.push_back(a);
            tot += a;
        }
        for (int k = 0; k <= N; ++k)
            for (int s = 0; s <= LIM; ++s)
                dp[k][s] = false;
        
        dp[0][SHIFT] = true;
        for (int v: sets) {
            for (int k=N; k>=1; k--) {
                for (int s=0; s<=LIM; s++) {
                    if (dp[k - 1][s]) {
                        int next_s = s + v;
                        if (0 <= next_s && next_s <= LIM) {
                            dp[k][next_s] = true;
                        }
                    }
                }
            }
        }
        
        long long mx = -1 * 1e15, mi = 1e15;
        for (int s=0; s<=LIM; s++) {
            if (!dp[N][s]) continue;
            int A = s - SHIFT;
            long long p = 1ll * A * (tot - A);
            if (p > mx) mx = p;
            if (p < mi) mi = p;
        }
        cout << mx << " " << mi << "\n";
    }
    return 0;
}
