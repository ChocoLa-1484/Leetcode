class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        auto end = nums.begin();
        for (const int x : nums) {
            auto it = upper_bound(nums.begin(), end, x);
            *it = x;
            if (it == end)  end++;
        }
        return nums.size() - (end - nums.begin());
    }
};

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (const int x : nums) {
            if (x == 1) one++;
            if (x == 2) two = max(one, two) + 1;
            if (x == 3) three = max({one, two, three}) + 1;
        }
        int maxi = max({one, two, three});
        return nums.size() - maxi;
    }
};