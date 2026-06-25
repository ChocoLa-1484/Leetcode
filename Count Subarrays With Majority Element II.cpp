struct Fenwick {
    int n;
    vector<int> s;
    int lowbit(int x) { return x & -x; }
    Fenwick(int _n) : n(_n) {
        s.assign(n + 1, 0);
    }
    void update(int i, int v) {
        for (; i < n; i += lowbit(i))
            s[i] += v;
    }
    int query(int x) {
        int pre = 0;
        for (; x; x -= lowbit(x))
            pre += s[x];
        return pre;
    }
    Fenwick(vector<int> a) {
        n = a.size();
        s.clear(), s.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            update(i, a[i - 1]);
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        Fenwick BIT(2 * n + 2);
        long long ans = 0;
        int cur = n + 1;
        BIT.update(cur, 1);
        for (int i : nums) {
            cur += (i == target) ? 1 : -1;
            ans += BIT.query(cur - 1);
            BIT.update(cur, 1);
        }
        return ans;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq((n << 1) + 1, 0);
        int cur = n;
        freq[cur] = 1;
        long long ans = 0, ok = 0;
        for (int i : nums) {
            ok += i == target ? freq[cur++] : -freq[--cur];
            ans += ok;
            freq[cur]++;
        }
        return ans;
    }
};