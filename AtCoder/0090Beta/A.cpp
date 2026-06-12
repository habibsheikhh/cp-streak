#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;
    for(int i=0; i<n; i++) {
        int sp, cost;
        cin >> sp >> cost;

        if(sp > cost) {
            ans += (sp-cost);
        }
    }
    cout << ans;

    return 0;
}