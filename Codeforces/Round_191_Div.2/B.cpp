#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cout << i << " ";
    }
    for(int i=1; i<=n; i++) {
        cout << i << " ";
    }
    for(int i=2; i<=n; i++) {
        cout << i << " ";
    }
    cout << 1 << " ";
    for(int i=1; i<=n; i++) {
        cout << i << " ";
    }
    cout << endl;
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