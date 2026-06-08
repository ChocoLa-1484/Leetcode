class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, pre = 0;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            l = (l + nums[i]) % k;
            if (s.count(l))
                return true;
            s.insert(pre);
            pre = l;
        }
        return false;
    }
};