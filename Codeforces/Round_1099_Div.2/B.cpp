#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int c = 0;

    for(int i=1; i<n; i++) {
        if(a[i-1] > a[i]) c = max(c,a[i-1]-a[i]);
    }
    for(int i=1; i<n; i++) {
        if(a[i-1] > a[i]) a[i] += c;
    }
    
    for(int i=1; i<n; i++) {
        if(a[i-1] > a[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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