#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, g;
    cin >> r >> g;

    int total = r + g;

    vector<int> dp(r + 1, 0);
    dp[0] = 1;

    int h = 1;
    for(; h*(h+1)/2 <= total; h++) {
        for(int red = r; red >= h; red--) {
            dp[red] = (dp[red] + dp[red-h]) % MOD;
        }
    }
    h--;
    int need = h*(h+1) / 2;
    int ans = 0;

    for(int red = 0; red <= r; red++) {
        int green = need - red;
        if(green <= g &&  green >= 0) {
            ans = (ans + dp[red]) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}