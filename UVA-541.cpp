// fun thinking problem
#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n && n > 0) {
        int m[n][n];
        int di = -1, dj = -1;
        int flag = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> m[i][j];
            }
        }

        for (int i=0; i<n; i++) {
            int c = 0;
            for (int j=0; j<n; j++) {
                c += m[i][j];
            }
            if (c % 2) {
                if (di == -1) di = i;
                else {
                    flag = 1;
                    break;
                }
            } 
        }


        for (int i=0; i<n; i++) {
            int c = 0;
            for (int j=0; j<n; j++) {
                c += m[j][i];
            }
            if (c % 2) {
                if (dj == -1) dj = i;
                else {
                    flag = 1;
                    break;
                }
            } 
        }
        if (flag) {
            cout << "Corrupt";
        } else {
            if (di != -1 && dj != -1) {
                cout << "Change bit (" << di + 1 << "," << dj + 1 << ")";
            } else {
                cout << "OK";
            }
        }
        nl;
    }

    return 0;
}
