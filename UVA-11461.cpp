#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    while (cin >> a >> b && a > 0 && b > 0) {
        int res = 0;
        for (int i=a; i<=b; i++) {
            double root = sqrt(i);
            if (floor(root) == ceil(root)) {
                res++;
            }
        }
        cout << res; nl;
    }

    return 0;
}
