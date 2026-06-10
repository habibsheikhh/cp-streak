#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> v(n);
    int cnt = 0;
    int minIdx = n;
    int mini = INT_MAX;
    for(int i=0; i<n; i++) {
        if(s[i] == '(') cnt++;
        else cnt--;
        v[i] = cnt;
        if(cnt < mini) {
            mini = cnt;
            minIdx = i;
        }
    }

    vector<int> ans(n);
    for(int i=0; i<n; i++) {
        if(k > 0 && ((i <= minIdx && s[i] == '(') || (i > minIdx && s[i] == ')'))) {
            ans[i] = 1;
            k--;
        }
        else ans[i] = 0;
    }

    for(int i=0; i<n; i++) {
        cout << ans[i];
    }

    cout << endl;

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