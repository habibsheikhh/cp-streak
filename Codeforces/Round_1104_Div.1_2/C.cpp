// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// void solve() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for(int i=0; i<n; i++) {
//         cin >> arr[i];
//     }
//     int i=0;
//     int maxSum = arr[0];
//     while(i<n-1) {
        
//         while(i<n-1 && arr[i] <= arr[i+1]) {
//             i++;
//         }
//         if(i==n-1) {
//             cout << arr[i] << '\n';
//             return;
//         }
//         int sum = arr[i] + arr[i+1];
//         i += 2;
//         while(i<n && sum > arr[i]) {
//             sum += arr[i];
//             i++;
//         }

//         if(i==n) {
//             cout << sum << '\n';
//             return;
//         }
//         maxSum = max(sum, arr[i]);
//     }
//     cout << maxSum << '\n';
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while(t--) {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// void solve() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for(int &x : arr) {
//         cin >> x;
//     }

//     int answer = arr[0];
//     int i = 0;

//     while(i < n) {
//         int current = arr[i];
//         i++;

//         while(i < n && current > arr[i]) {
//             current += arr[i];
//             i++;
//         }

//         answer = max(answer, current);
//     }

//     cout << answer << '\n';
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while(t--) {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// void solve() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int sum = arr[0];
//     int ans = arr[0];

//     for(int i = 1; i < n; i++) {
//         if(sum > arr[i]) {
//             sum += arr[i];
//         }
//         else {
//             ans = max(ans, sum);
//             sum = arr[i];
//         }
//     }

//     ans = max(ans, sum);

//     cout << ans << '\n';
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while(t--) {
//         solve();
//     }

//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    int sum;
    cin >> sum;
    int ans = sum;

    for(int i=1; i<n; i++) {
        int k;
        cin >> k;
        if(sum > k) {
            sum += k;
        } else {
            ans = max(ans,sum);
            sum = k;
        }
    }

    ans = max(ans, sum);

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