#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            break;
        }
        long long carry = 0, happen = 0;
        while (a > 0 || b > 0 || carry > 0) {
            int d = a % 10 + b % 10 + carry;
            if (d >= 10) happen++;
            a = a / 10;
            b = b / 10;
            carry = d / 10;
        }
        if (happen == 0) {
            cout << "No carry operation.";
        } else if (happen == 1) {
            cout << happen << " carry operation.";
        } else {
            cout << happen << " carry operations.";
        }
        nl;
    }
    return 0;
}
