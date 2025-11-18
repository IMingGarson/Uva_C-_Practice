// Decent practice for Dijsktra
#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

const long long INF = 1e15;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    for (int i=1; i<=tc; i++) {
        cout << "Case #" << i << ": ";
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<pair<int, long long>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, INF);
        dist[s] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0ll, s});
        while (!pq.empty()) {
            pair<long long, int> cur = pq.top(); pq.pop();
            int cur_node = cur.second;
            int cur_w = cur.first;
            for (pair<int, long long> neighbor: adj[cur_node]) {
                if (dist[neighbor.first] > dist[cur_node] + neighbor.second) {
                    dist[neighbor.first] = dist[cur_node] + neighbor.second;
                    pq.push({dist[neighbor.first], neighbor.first});
                }
            }
        }
        if (dist[t] == INF) {
            cout << "unreachable";
        } else {
            cout << dist[t];
        }
        nl;
    }
    return 0;
}
