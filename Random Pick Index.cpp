class Solution {
public:
    unordered_map<int, vector<int>> mp;
    mt19937 gen;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].emplace_back(i);
        }
        mt19937 gen(random_device());
    }

    int pick(int target) {
        auto &v = mp[target];
        uniform_int_distribution<int> unif(0, v.size() - 1);
        return v[unif(gen)];
    }
};

class Solution {
public:
    vector<int> nums;
    mt19937 gen;
    Solution(vector<int>& nums)
        : nums(nums), gen(random_device{}()) {}

    int pick(int target) {
        int ans = -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) continue;
            cnt++;
            uniform_int_distribution<int> dist(1, cnt);
            if (dist(gen) == 1)
                ans = i;
        }
        return ans;
    }
};