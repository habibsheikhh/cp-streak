#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Event {
    int l, r, c;
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    cin >> n >> b;

    vector<Event> v(n);
    int totalC = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r >> v[i].c;
        totalC += v[i].c;
    }

    sort(v.begin(), v.end(), [](const Event &a, const Event &b) {
        return a.r < b.r;
    });

    vector<int> ends(n);
    for (int i = 0; i < n; i++) {
        ends[i] = v[i].r;
    }

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int l = v[i - 1].l;
        int c = v[i - 1].c;

        int prev = upper_bound(ends.begin(), ends.end(), l) - ends.begin();

        int take = dp[prev] + b + c;
        int skip = dp[i - 1];

        dp[i] = max(skip, take);
    }

    cout << dp[n] - totalC << '\n';

    return 0;
}