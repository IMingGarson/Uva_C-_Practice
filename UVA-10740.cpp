#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m && n > 0 && m > 0) {
        int x, y, k; cin >> x >> y >> k;
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i=0; i<m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }
        vector<long long> dist(n + 1, 1ll << 60);
        dist[x] = 0;
        vector<int> count(n + 1, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        // dist, node
        pq.push({0, x});
        int flag = 0;
        while (!pq.empty()) {
            pair<long long, int> curr = pq.top(); pq.pop();
            long long p_size = curr.first;
            int node = curr.second;
            if (count[node] >= k) {
                continue;
            }
            count[node] += 1;
            if (y == node && count[y] == k) {
                flag = 1;
                cout << p_size; nl;
                break;
            }
            for (pair<int, int> neighbor: graph[node]) {
                pq.push({ p_size + neighbor.second, neighbor.first});
            }
        }
        if (!flag) {
            cout << -1; nl;
        }
    }


    return 0;
}
