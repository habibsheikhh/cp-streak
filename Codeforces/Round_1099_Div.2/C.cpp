#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    unordered_map<int,int> cnt;
    unordered_map<int,int> cost;

    for(int i=0; i<n; i++) {
        cin >> a[i];

        int x = a[i];
        int steps = 0;

        while(true) {
            cnt[x]++;
            cost[x] += steps;

            if(x == 1) {
                cnt[2]++;
                cost[2] += steps + 1;
                break;
            }

            if(1 & x) {
                x++;
            } else x /= 2;

            steps++;
        }

    }
    int ans = 1e18;

    for(auto &[val,freq] : cnt) {
        if(freq == n) {
            ans = min(ans, (int)cost[val]);
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
