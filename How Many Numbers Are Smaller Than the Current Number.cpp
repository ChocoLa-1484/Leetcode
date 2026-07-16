class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        int cnt[102] = {};
        for (int i : nums)
            cnt[i + 1]++;
         for (int i = 1; i < 102; ++i)
            cnt[i] += cnt[i - 1];
        for (int& i : nums)
            i = cnt[i];
        return nums;
    }
};