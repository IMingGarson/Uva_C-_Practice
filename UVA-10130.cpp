// Decent 0/1 practice
#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

vector<pair<int, int>> items;
int memo[1005][35];
int N;
int f(int i, int limit) {
    if (i >= N || limit <= 0) {
        return 0;
    }
    if (memo[i][limit] != -1) {
        return memo[i][limit];
    }
    int res = f(i + 1, limit);
    if (items[i].second <= limit) {
        res = max(res, items[i].first + f(i + 1, limit - items[i].second));
    }
    memo[i][limit] = res;
    return memo[i][limit];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    for (int i=1; i<=tc; i++) {
        cin >> N;
        items.clear();
        items.resize(N);
        for (int i=0; i<N; i++) {
            int p, w; cin >> p >> w;
            items[i] = make_pair(p, w);
        }
        int G;
        cin >> G;
        vector<int> W(G);
        int maxW = 0;
        for (int i = 0; i < G; i++) {
            cin >> W[i];
            maxW = max(maxW, W[i]);
        }

        for (int i = 0; i <= N; i++) {
            for (int w = 0; w <= maxW; w++) {
                memo[i][w] = -1;
            }
        }
        int r = 0;
        for (int i=0; i<G; i++) {
            r += f(0, W[i]);
        }
        cout << r; nl;
    }
    return 0;
}
