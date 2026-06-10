#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n,k;
    cin >> n >> k;

    int a[n] = {};
    int ans = 0;
    while(k > 0) {
        for(int i=0; k>0 && i<n; i++) {
            a[i] += k;
            k--;
            ans = max(ans,a[i]);
        }
        for(int i=n-1; k>0 && i>=0; i--) {
            a[i] += k;
            k--;
            ans = max(ans,a[i]);
        }
    }
    cout << ans << endl;
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