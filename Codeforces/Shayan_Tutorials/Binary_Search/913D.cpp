#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isPossible(int mid, int T, vector<pair<int,int>>& arr) {
    vector<pair<int,int>> temp; // {time, a}

    for(auto p : arr) {
        int a = p.first;
        int time = p.second;

        if(a >= mid) {
            temp.push_back({time, a});
        }
    }

    if((int)temp.size() < mid) return false;

    sort(temp.begin(), temp.end());

    int totalTime = 0;

    for(int i = 0; i < mid; i++) {
        totalTime += temp[i].first;
    }

    return totalTime <= T;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, T;
    cin >> n >> T;

    vector<pair<int,int>> arr(n); // {a, time}

    for(int i = 0; i < n; i++) {
        int a, time;
        cin >> a >> time;

        arr[i] = {a, time};
    }

    int lo = 0, hi = n + 1;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if(isPossible(mid, T, arr)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << '\n';
    cout << lo << '\n';

    vector<pair<int,int>> ans; // {time, index}

    for(int i = 0; i < n; i++) {
        int a = arr[i].first;
        int time = arr[i].second;

        if(a >= lo) {
            ans.push_back({time, i + 1});
        }
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < lo; i++) {
        cout << ans[i].second << " ";
    }

    cout << '\n';

    return 0;
}