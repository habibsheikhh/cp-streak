#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for(int i=0; i<k; i++) {
        int cnt = 0;

        for(int j=i; j<n; j+=k) {
            if(s[j] == '1') cnt++;
        }
        if(cnt % 2) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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