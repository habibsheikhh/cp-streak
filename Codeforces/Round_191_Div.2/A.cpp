#include <bits/stdc++.h>
using namespace std;

#define int long long

int ceilDiv(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    int noAI = ceilDiv(n, x + y);

    int writtenDuringSetup = x * z;
    int useAI;

    if (writtenDuringSetup >= n) {
        // Project finishes before AI setup ends
        useAI = ceilDiv(n, x);
    } else {
        int remaining = n - writtenDuringSetup;
        int afterSetupTime = ceilDiv(remaining, x + 10 * y);
        useAI = z + afterSetupTime;
    }

    cout << min(noAI, useAI) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}