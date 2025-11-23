#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

vector<int> to;
vector<bool> check, sum;
int times;
void dfs(int node) {
    ++times;
    sum[node] = check[node] = true;
    if (!check[to[node]]) dfs(to[node]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    int n;
    for (int tc=1; tc<=T; tc++) {
        cin >> n;
        to.assign(n + 1, -1);
        sum.assign(n + 1, false);

        for (int j = 0; j < n; ++j) {
            int a, b;
            cin >> a >> b, to[a] = b;
        }
        int gt = 1;
        int starter = to[1];
        for (int i=1; i<=n; i++) {
            if (!sum[i]) {
                check.assign(n + 1, false);
                check[i] = true;
                times = 1;
                dfs(to[i]);
                if (times > gt || (times == gt && i < starter)) {
                    gt = times;
                    starter = i;
                }
            }
        }
        cout << "Case " << tc << ": " << starter; nl;
    }
    return 0;
}
