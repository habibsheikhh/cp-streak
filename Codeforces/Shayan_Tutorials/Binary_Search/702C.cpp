#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;

    cin >> n >> m;

    vector<int> city(n);

    for(int i=0; i<n; i++) {
        cin >> city[i];
    }

    vector<int> tower(m);

    for(int i=0; i<m; i++) {
        cin >> tower[i];
    }

    sort(tower.begin(),tower.end());

    int minDist = 0;

    for(int i=0; i<n; i++) {
        int lo = 0, hi = m-1;
        int lb = -1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            if(tower[mid] <= city[i]) {
                lb = mid;
                lo = mid + 1;
            }
            else {
                hi = mid-1;
            }
        }

        int ub = upper_bound(tower.begin(), tower.end(), city[i]) - tower.begin();

        int ans = LLONG_MAX;

        if(lb != -1) {
            ans = min(ans, city[i] - tower[lb]);
        }

        if(ub != m) {
            ans = min(ans, tower[ub] - city[i]);
        }

        minDist = max(minDist, ans);
    }

    cout << minDist << '\n';

    return 0;
}