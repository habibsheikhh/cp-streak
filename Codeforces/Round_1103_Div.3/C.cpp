#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int a, b, x;
    cin >> a >> b >> x;

    int arr1[32];
    int arr2[32];
    int c = a, d = b;
    for(int i=0; i<32; i++) {
        arr1[i] = c;
        arr2[i] = d;
        c /= x;
        d /= x;
    }

    int i = 0, j = 0;

    int ans = LLONG_MAX;
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 32; j++) {
            int diff = abs(arr1[i] - arr2[j]);
            ans = min(ans, diff + i + j);
        }
    }

    cout << ans << '\n';
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