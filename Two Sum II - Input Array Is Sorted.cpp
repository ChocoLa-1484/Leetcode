class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        while (1) {
            if (numbers[l] + numbers[r] == target)
                break;
            if (numbers[l] + numbers[r] > target) 
                r--;
            else
                l++;
        }
        return {l + 1, r + 1};
    }
};