#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (getline(cin, s), s != "0") {
        int c = 0;
        while (s.size() > 1) {
            int base = 1;
            int r = 0;
            for (int i=s.size()-1; i>=0; i--) {
                int digit = s[i] - '0';
                r += digit;
            }
            s = to_string(r);
        }
        cout << s << endl;
    }
    return 0;
}
