#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> pre(n+1, 0);
    vector<int> suf(n+1, 0);

    for(int i=0; i<n; i++) {
        pre[i+1] = pre[i] + (s[i]=='(');
    }
    for(int i=n-1; i>=0; i--) {
        suf[i] = suf[i+1] + (s[i]==')');
    }

    int best = INT_MAX;
    int cut = 0;

    for(int i=0; i<=n; i++) {
        int curr = pre[i] + suf[i];
        if(best > curr) {
            cut = i;
            best = curr;
        }
    }

    string ans(n, '0');

    int rem = k;

    for(int i=0; i<n && rem > 0; i++) {
        if(i < cut && s[i]=='(') {
            ans[i] = '1'; rem--;
        } else if (i >= cut && s[i]==')') {
            ans[i] = '1'; rem--;
        }
    }

    cout << ans << '\n';

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