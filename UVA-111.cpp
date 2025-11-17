#include <bits/stdc++.h>
using namespace std;

// Kinda bullshit description but it's basically LCS or LIS

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<int> correct(n + 1);
        int a;
        for (int i=1; i<=n; i++) {
            cin >> a;
            correct[a] = i;
        }
        int stu1 = 0;
        while (cin >> stu1) {
            int res = -1;
            vector<int> student(n + 1);
            vector<vector<int>> LCS(n + 1, vector<int>(n + 1, 0));
            student[stu1] = 1;
            for (int i=2; i<=n; i++) {
                int pos; cin >> pos;
                student[pos] = i;
            }
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if (correct[i] == student[j]) {
                        LCS[i][j] = LCS[i - 1][j - 1] + 1;
                    } else {
                        LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
                    }
                    res = max(LCS[i][j], res);
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}
