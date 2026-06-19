#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        int val = arr[i - 1];

        int hourPass = lower_bound(arr.begin(), arr.end(), val - 89) - arr.begin();
        int dayPass = lower_bound(arr.begin(), arr.end(), val - 1439) - arr.begin();

        dp[i] = min({
            dp[i - 1] + 20,
            dp[hourPass] + 50,
            dp[dayPass] + 120
        });

        cout << dp[i] - dp[i - 1] << '\n';
    }

    return 0;
}