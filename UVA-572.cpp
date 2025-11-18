// Basically LeetCode "number of islands"
#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<string> grid;
int m, n;
void dfs(int i, int j) {
    for (pair<int, int> p: dirs) {
        int dx = i + p.first, dy = j + p.second;
        if (0 <= dx && dx < m && 0 <= dy && dy < n && grid[dx][dy] == '@') {
            grid[dx][dy] = '*';
            dfs(dx, dy);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> m >> n, m, n) {
        int res = 0;
        grid.reserve(m);
        grid.assign(m, "");
        for (int i=0; i<m; i++) {
            cin >> grid[i];
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '@') {
                    res++;
                    grid[i][j] = '*';
                    dfs(i, j);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
