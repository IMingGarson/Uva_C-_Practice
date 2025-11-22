// backtrace
#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

void f(int i, vector<int>& set, vector<int>& cand) {
    if ((int) cand.size() == 6) {
        for (int i=0; i<6; i++) {
            cout << cand[i];
            if (i < 5) {
                cout << " ";
            }
        }
        nl;
        return;
    }
    for (int j=i; j<(int)set.size(); j++) {
        cand.push_back(set[j]);
        f(j + 1, set, cand);
        cand.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    int ne = 0;
    while (cin >> k && k > 0) {
        if (ne++) nl;
        vector<int> lotto(k);
        vector<int> cand;
        for (int &x: lotto) cin >> x;
        f(0, lotto, cand);
    }
    return 0;
}
