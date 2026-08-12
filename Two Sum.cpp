class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (hash.count(t))    
                return {i, hash[t]};
            hash[nums[i]] = i;
        }
        return {};
    }
};