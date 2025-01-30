struct fenwick {
    vector<int> fn;
    int n;

    void init(int n) {
        this->n = n + 1;
        fn.resize(this->n, 0);
    }

    void add(int idx, int val) {
        idx++; // 1 based index
        while (idx < n) {
            fn[idx] += val;
            idx += (idx & (-idx));// last set bit
        }
    }

    // void add(int idx, int y) {
    // 	for (idx++; idx < n; idx += (idx & (-idx))) fn[idx] += y;
    // }

    int sum(int idx) {
        idx++; // 1 based index
        int ans = 0;
        while (idx) {
            ans += fn[idx];
            idx -= (idx & (-idx));// last set bit
        }
        return ans;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

};