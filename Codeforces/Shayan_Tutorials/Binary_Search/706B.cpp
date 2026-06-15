#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n, -1);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int k;
    cin >> k;

    for(int i=0; i<k; i++) {
        int coins;
        cin >> coins;

        cout << upper_bound(arr.begin(),arr.end(),coins) - arr.begin() << '\n';
    }

    return 0;
}