#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

vector<int> UF;
int FIND(int x){
    if (UF[x] == x) return x;
    return UF[x] = FIND(UF[x]);
}
void UNION(int x, int y){
    if (FIND(x)!=FIND(y))
        UF[FIND(x)] = FIND(y);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        int n, m; cin >> n >> m;
        UF.resize(n+1);
        for (int i=1; i<=n; i++) UF[i] = i;
        long long total = 0;
        vector<pair<int, int>> graph;
        priority_queue<pair<int, int>> q;
        for (int i=0; i<m; i++) {
            int u, v, w; cin >> u >> v >> w;
            graph.push_back({u, v});
            total += w;
            q.push({w, i});
        }
        while (!q.empty()) {
            int cost = q.top().first;
            int node = q.top().second;
            q.pop();
            if (FIND(graph[node].first) != FIND(graph[node].second)) {
                total -= cost;
                UNION(graph[node].first, graph[node].second);
            }
        }
        cout << total; nl;
    }

    return 0;
}
