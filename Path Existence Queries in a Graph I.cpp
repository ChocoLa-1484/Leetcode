class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> pa(n);
        pa[0] = 0;
        int now = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) 
                now = i;
            pa[i] = now;
        }
        int m = queries.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            auto& Q = queries[i];
            ans[i] = pa[Q[0]] == pa[Q[1]];
        }
        return ans;
    }
};