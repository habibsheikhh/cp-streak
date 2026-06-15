#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXA = 1000000;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cnt(MAXA + 1, 0);

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for(int y = 1; y * y <= x; y++) {
            if(x % y == 0) {
                cnt[y]++;

                if(y * y != x) {
                    cnt[x / y]++;
                }
            }
        }
    }

    vector<int> dp(MAXA + 1, 0);

    int a = dp.size();

    int MOD = 1e9 + 7;

    vector<int> power2(n + 1, 1);

    for(int i = 1; i <= n; i++) {
        power2[i] = (power2[i - 1] * 2) % MOD;
    }

    for(int i = 1; i < a; i++) {
        if(cnt[i] > 0) {
            dp[i] = (cnt[i] * power2[cnt[i] - 1]) % MOD;
        }
    }

    for(int i = a - 1; i > 0; i--) {
        for(int j = 2 * i; j < a; j += i) {
            dp[i] = (dp[i] - dp[j] + MOD) % MOD;
        }
    }

    int ans = 0;

    for(int i = 2; i < a; i++) {
        ans = (ans + i * dp[i]) % MOD;
    }

    cout << ans << '\n';

    return 0;
}