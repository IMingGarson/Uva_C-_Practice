#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<long long>> dist(n, vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> dist[i][j];
            }
        }
        vector<long long> order(n);
        for (int i=0; i<n; i++) {
            cin >> order[i];
        }
        reverse(order.begin(), order.end());

        long long res = 0;
        vector<bool> alive(n, false);
        for (int o: order) {
            alive[o] = true;
            for (int i=0; i<n; i++) {
                if (dist[i][o] == INF) continue;
                for (int j=0; j<n; j++) {
                    if (dist[o][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][o] + dist[o][j]);
                }
            }

            long long running = 0;
            for (int i=0; i<n; i++) {
                if (alive[i]) {
                    for (int j=0; j<n; j++) {
                        if (alive[j] && dist[i][j] < INF) {
                            running += dist[i][j];
                        }
                    }
                }
            }
            res += running;
        }
        cout << res << "\n";
    }
    return 0;
}
