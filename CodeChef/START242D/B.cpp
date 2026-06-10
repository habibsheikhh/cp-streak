#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n,m;
    cin >> n >> m;

    string a,b;
    cin >> a >> b;

    int finalLen = min(n, m);
    for(int i=0; i<min(n,m); i++) {
        if(a[i] != b[i]) {
            finalLen = i; break;
        }
    }
    cout << a.substr(0, finalLen);

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