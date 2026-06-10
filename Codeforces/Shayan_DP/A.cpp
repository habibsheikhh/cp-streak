#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[150000], b[150000], ans[150000];

    for(int i=0; i<100001; i++) {
        cin >> a[i];
        b[a[i]]++;
    }

    ans[1] = b[1];

    for(int i=2; i<100001; i++) {
        ans[i] = max(ans[i-1], (b[i]*i) + ans[i-2]);
    }

    cout << ans[100000];
    

    return 0;
}