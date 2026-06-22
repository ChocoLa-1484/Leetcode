class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> v;
        int n = nums.size(), ll = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int l = max(ll, i - k), r = min(i + k, n - 1);
                for (int j = l; j <= r; j++)
                    v.push_back(j);
                ll = r + 1;
            }
        }
        return v;
    }
};