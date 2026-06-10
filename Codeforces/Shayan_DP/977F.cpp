#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int,int> dp;

    int a[n];
    int ans = 0, curr = 0;


    for(int i=0; i<n; i++) {
        cin >> a[i];
        dp[a[i]] = dp[a[i]-1] + 1;
        
        if(dp[a[i]] > ans) {
            ans = dp[a[i]];
            curr = a[i];
        }
    }

    cout << ans << endl;

    vector<int> vec;

    for(int i=n-1; i>=0; i--) {
        if(a[i] == curr) {
            vec.push_back(i);
            curr--;
        }
    }
    reverse(vec.begin(),vec.end());

    for(int i=0; i<vec.size(); i++) {
        cout << vec[i]+1 << " ";
    }
    return 0;
}