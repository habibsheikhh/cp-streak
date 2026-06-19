// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// void solve() {
//     int n;
//     cin >> n;

//     vector<int> a(n), b(n);

//     for(int i = 0; i < n; i++) cin >> a[i];
//     for(int i = 0; i < n; i++) cin >> b[i];

//     vector<bool> vis(n, false);
//     vector<int> pos;

//     for(int i = 0; i < n; i++) {
//         int idx = -1;

//         for(int j = 0; j < n; j++) {
//             if(!vis[j] && a[j] <= b[i]) {
//                 idx = j;
//                 break;
//             }
//         }

//         if(idx == -1) {
//             cout << -1 << '\n';
//             return;
//         }

//         vis[idx] = true;
//         pos.push_back(idx);
//     }

//     int swaps = 0;

//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             if(pos[i] > pos[j]) {
//                 swaps++;
//             }
//         }
//     }

//     cout << swaps << '\n';
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

    vector<int> a(n);
    vector<int> b(n);

    for(int i=0; i<2*n; i++) {
        if(i<n) {
            cin >> a[i];
        } else {
            cin >> b[i%n];
        }
    }

    vector<bool> vis(n, false);

    for(int i=0; i<n; i++) { // for every value in b
        int val = b[i];
        bool changed = false;
        for(int j=0; j<n; j++) {
            if(!vis[j] && a[j] <= val) {
                changed = true;
                a[j] = val;
                vis[j] = true;
                break;
            }
        }
        if(!changed) {
            cout << -1 << '\n';
            return;
        }
    }

    int swaps = 0;
    bool changed = true;

    while(changed) { // bubble sort
        changed = false;
        for(int j=0; j<n-1; j++) {
            if(a[j] > a[j+1]) {
                changed = true;
                swaps++;
                swap(a[j],a[j+1]);
            }
        }
    }

    cout << swaps << '\n';

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