class SparseTable {
public:
    vector<vector<int>> st;
    function<int(int, int)> op;
    SparseTable(const vector<int>& nums, function<int(int, int)> f) {
        size_t n = nums.size();
        op = f;
        int w = __lg(n) + 1;
        st.assign(w, vector<int>(n));
        for (int i = 0; i < n; i++) {
            st[0][i] = nums[i];
        }
        for (int i = 1; i < w; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) { // [l, r)
        int k = __lg(r - l);
        return op(st[k][l], st[k][r - (1 << k)]);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable st_mx(nums, [](int a, int b) { return max(a, b); });
        SparseTable st_mn(nums, [](int a, int b) { return min(a, b); });
        using T = array<int, 3>;
        auto cmp = [](const T& a, const T& b) { return a[0] < b[0]; };
        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < n; i++) {
            pq.push({st_mx.query(i, n) - st_mn.query(i, n), i, n});
        }

        long long res = 0;
        while (!pq.empty() && pq.top()[0] > 0 && k--) {
            auto top = pq.top();
            pq.pop();

            res += top[0];
            top[2]--;
            if (top[1] < top[2]) {
                top[0] = st_mx.query(top[1], top[2]) - st_mn.query(top[1], top[2]);
                pq.push(top);
            }
        }
        return res;
    }
};