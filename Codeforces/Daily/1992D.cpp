#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    s = "L" + s + "L";

    vector<int> dp(n+2, 1e18);

    dp[0] = 0;

    for(int i=0; i<=n; i++) {
        if(dp[i] > k) continue;
        if(s[i] == 'C') continue;

        if(s[i] == 'L') {
            for(int j=i+1; j<=min(n+1,i+m); j++) {
                if(s[j] != 'C') {
                    dp[j] = min(dp[j],dp[i]);
                }
            }
        }

        if(s[i] == 'W') {
            if(i+1 <= n+1 && s[i+1] != 'C') {
                dp[i+1] = min(dp[i+1], dp[i] + 1);
            }
        }
    }

    cout << ((dp[n+1] > k) ? "NO" : "YES") << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}