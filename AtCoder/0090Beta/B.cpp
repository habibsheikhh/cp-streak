#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, n, c;
    cin >> l >> n >> c;

    int battery = c;
    int prevStation = 0;

    for (int i = 0; i < n; i++) {
        int p, w;
        cin >> p >> w;

        battery -= (p - prevStation);

        if (battery < 0) {
            cout << -1;
            return 0;
        }

        battery += w;
        if (battery > c) battery = c;

        prevStation = p;
    }

    // travel from last station to goal
    battery -= (l - prevStation);

    if (battery < 0) cout << -1;
    else cout << battery;

    return 0;
}