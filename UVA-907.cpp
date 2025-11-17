#include <bits/stdc++.h>
using namespace std;

bool ok(long long mile, vector<long long>& campsite, int limit) {
    int days = 1;
    long long running_mile = 0;
    for (long long path: campsite) {
        if (path > mile) {
            return false;
        }
        if (running_mile + path <= mile) {
            running_mile += path;
        } else {
            days++;
            running_mile = path;
        }
    }
    return days <= limit;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    while (cin >> N >> K) {
        vector<long long> camp(N + 1);
        long long left = 1;
        long long right = 1e10;
        for (long long &x: camp) {
            cin >> x;
        }
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (ok(mid, camp, K + 1)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << left << endl;
    }

    return 0;
}
