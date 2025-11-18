// keep an eye on this IO
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char c;
    int seen_left = 0;
    while (cin.get(c)) {
        if (c == '"') {
            if (seen_left == 0) {
                seen_left = 1;
                cout << "``";
            } else {
                seen_left = 0;
                cout << "''";
            }
        } else {
            cout << c;
        }
    }
    return 0;
}
