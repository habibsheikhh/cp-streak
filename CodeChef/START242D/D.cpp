#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    if(A == B) {
        cout << 0 << endl;
    }
    else if(__gcd(A, C) == __gcd(B, C)) {
        cout << 1 << endl;
    }
    else if(__gcd(A, C + 1) == __gcd(B, C + 1)) {
        cout << 2 << endl;
    }
    else {
        cout << 3 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}