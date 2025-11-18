// Interesting slide window
#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    for (int i=1; i<=T; i++) {
        cout << "Case " << i << ": ";
        int N, M, K; cin >> N >> M >> K;
        if (K <= 3) {
            if (K == 1) {cout << 1; nl;}
            else if (K == 2) {cout << 2; nl;}
            else {cout << 3; nl;}
            continue;
        }
        vector<int> seq = {1, 2, 3};
        for (int i=2; i<N-1; i++) {
            int n = (seq[i] + seq[i - 1] + seq[i - 2]) % M + 1;
            seq.emplace_back(n);
        }
        int res = 1e7;
        int left = 0;
        vector<int> cnt(K + 1, 0);
        int have = 0;
        for (int i=0; i<seq.size(); i++) {
            if (seq[i] <= K) {
                if (cnt[seq[i]] == 0) {
                    have++;
                }
                cnt[seq[i]]++;
            }
            while (have == K && left < i) {
                res = min(res, i - left + 1);
                if (seq[left] <= K) {
                    cnt[seq[left]]--;
                    if (cnt[seq[left]] == 0) {
                        have--;
                    }
                }
                left++;
            }
            
        }
        if (res == 1e7) {
            cout << "sequence nai";
        } else {
            cout << res;
        }
        nl;
    }
    return 0;
}
