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


// For Maximum Index Range

struct SegTree {
    int n;
    vector<int> seg;

    SegTree () {}

    SegTree(int _n) {
        n = _n;
        seg.assign(4 * n + 5, 0);
    }

    void build(int i, int l, int r, vector<int>& a) {
        if (l == r) {
            seg[i] = l;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * i + 1, l, mid, a);
        build(2 * i + 2, mid + 1, r, a);

        int leftQ = seg[2 * i + 1];
        int rightQ = seg[2 * i + 2];

        if(a[leftQ] >= a[rightQ]) {
            seg[i] = leftQ;
        } 
        else seg[i] = rightQ;
    }

    long long query(int i, int l, int r, int ql, int qr, vector<int>& a) {
        // No overlap
        if (r < ql || l > qr) return -1;

        // Complete overlap
        if (ql <= l && r <= qr) return seg[i];

        int mid = (l + r) / 2;

        int leftQ = query(2 * i + 1, l, mid, ql, qr, a);
        int rightQ = query(2 * i + 2, mid+1, r, ql, qr, a);
        if(leftQ == -1) return rightQ;
        if(rightQ == -1) return leftQ;
        if(a[leftQ] >= a[rightQ]) {
            return leftQ;
        }
        return rightQ;
    }

    void update(int i, int l, int r, int pos, int val, vector<int>& a) {
        if (l == r) {
            seg[i] = pos;
            a[pos] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * i + 1, l, mid, pos, val, a);
        else
            update(2 * i + 2, mid + 1, r, pos, val, a);

        int leftQ = seg[2*i+1];
        int rightQ = seg[2*i+2];
        if(a[leftQ] >= a[rightQ]) {
            seg[i] = leftQ;
        } 
        else seg[i] = rightQ;
    }
};
