#include <bits/stdc++.h>
using namespace std;

#define int long long

long long C[70][70];

long long countOnes(long long x, int k) {
    if (x <= 0) return 0;

    long long ans = 0;
    int ones = 0;

    for (int bit = 63; bit >= 0; bit--) {
        if ((x >> bit) & 1LL) {
            int remainingBits = bit;
            int need = k - ones;

            if (need >= 0 && need <= remainingBits) {
                ans += C[remainingBits][need];
            }

            ones++;
        }
    }

    if (ones == k) ans++;

    return ans;
}

long long good(long long n, int k) {
    return countOnes(2 * n, k) - countOnes(n, k);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long m;
    int k;
    cin >> m >> k;

    for (int i = 0; i < 70; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = min((long long)4e18, C[i - 1][j - 1] + C[i - 1][j]);
        }
    }

    long long lo = 1, hi = 1e18, ans = 1;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        if (good(mid, k) >= m) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}