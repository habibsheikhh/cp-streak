#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    for(int i=0; i<n; i++) {
        int m,c,x;
        cin >> m >> c >> x;

        int t = m+c+x;

        int l=0, r=(t/3)+1;
        while(l+1 < r) {
            int mid = (l+r) / 2;

            if(mid <= m && mid <=c && (3*mid) <= t) {
                l = mid;
            }
            else r = mid;
        }
        cout << l << '\n';
    }

    return 0;
}