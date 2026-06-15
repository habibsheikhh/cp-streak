#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    int arr[n];
    cin >> arr[0];

    for(int i=1; i<n; i++) {
        int val;
        cin >> val;
        arr[i] = abs(val-arr[0]);
    }

    int totalGcd = 0;

    for(int i=1; i<n; i++) {
        totalGcd = __gcd(totalGcd,arr[i]);
    }

    for(int i=0; i<m; i++) {

        int val;
        cin >> val;

        int newEle = arr[0] + val;

        cout << __gcd(newEle,totalGcd) << '\n';
 
    }

    return 0;
}