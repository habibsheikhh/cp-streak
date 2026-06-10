#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n,d,x;

    cin >> n >> d >> x;

    if(d >= x || d >= n-x+1) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;

    
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