#include <bits/stdc++.h>
using namespace std;

#define int long long

bool good(vector<int>& a) {
    unordered_set<int> seen;
    int n = a.size();

    for(int i = 0; i < n; ) {
        int val = a[i];

        if(seen.count(val)) return false;
        seen.insert(val);

        while(i < n && a[i] == val) i++;
    }

    return true;
}

void solve() {

    // This solution gives a TLE on test case 10.

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(good(a)) {
        cout << "YES\n";
        return;
    }

    vector<int> l, r, val;

    for(int i = 0; i < n; ) {
        int j = i;

        while(j < n && a[j] == a[i]) j++;

        l.push_back(i);
        r.push_back(j - 1);
        val.push_back(a[i]);

        i = j;
    }

    int m = val.size();

    unordered_map<int, int> blocks;

    for(int x : val) {
        blocks[x]++;
    }

    vector<int> badValues;

    for(auto &[x, cnt] : blocks) {
        if(cnt > 1) {
            badValues.push_back(x);

            if(cnt > 3) {
                cout << "NO\n";
                return;
            }
        }
    }

    if(badValues.size() > 2) {
        cout << "NO\n";
        return;
    }

    set<int> candidates;

    for(int i = 0; i < m; i++) {
        bool bad = false;

        for(int x : badValues) {
            if(val[i] == x) bad = true;
        }

        if(!bad) continue;

        for(int j = max(0LL, i - 1); j <= min((int)m - 1, i + 1); j++) {
            candidates.insert(l[j]);
            candidates.insert(r[j]);
        }
    }

    vector<int> cand(candidates.begin(), candidates.end());

    for(int i = 0; i < cand.size(); i++) {
        for(int j = i + 1; j < cand.size(); j++) {
            swap(a[cand[i]], a[cand[j]]);

            if(good(a)) {
                cout << "YES\n";
                return;
            }

            swap(a[cand[i]], a[cand[j]]);
        }
    }

    cout << "NO\n";
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