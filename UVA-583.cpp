// Prime factor practice
#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

int int_sqrt (int x) {
  int ans = 0;
  for (int k = 1 << 15; k != 0; k /= 2) {
    if ((ans + k) * (ans + k) <= x) {
      ans += k;
    }
  }
  return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 55555;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    int N;
    while (cin >> N && N != 0) {
        cout << N << " = ";
        if (N < 0) {
            N *= -1;
            cout << "-1 x ";
        }
        vector<int> factor;
        int T = N;
        for (int i=2; i<=int_sqrt(N); i++) {
            if (!is_prime[i] || T % i != 0) continue;
            while (T % i == 0) {
                factor.emplace_back(i);
                T /= i;
            }
        }
        if (T > 1) {
            factor.emplace_back(T);
        }
        for (int i=0; i<(int)factor.size(); i++) {
            if (i > 0) cout << " x ";
            cout << factor[i];
        }
        nl;
    }

    return 0;
}
