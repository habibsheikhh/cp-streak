#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SegTree {
    int n;
    vector<long long> seg;

    SegTree(int _n) {
        n = _n;
        seg.assign(4 * n + 5, 0);
    }

    void build(int i, int l, int r, vector<long long>& a) {
        if (l == r) {
            seg[i] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * i + 1, l, mid, a);
        build(2 * i + 2, mid + 1, r, a);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    long long query(int i, int l, int r, int ql, int qr) {
        // No overlap
        if (r < ql || l > qr) return 0;

        // Complete overlap
        if (ql <= l && r <= qr) return seg[i];

        int mid = (l + r) / 2;

        return query(2 * i + 1, l, mid, ql, qr)
             + query(2 * i + 2, mid + 1, r, ql, qr);
    }

    void update(int i, int l, int r, int pos, long long val) {
        if (l == r) {
            seg[i] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * i + 1, l, mid, pos, val);
        else
            update(2 * i + 2, mid + 1, r, pos, val);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
};

void solve() {
    int n,q;
    cin >> n >> q;

    SegTree st(n);
    while (q--) {
        int op,l,r;
        cin >> op >> l >> r;


        // WILL UPSOLVE
    }
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