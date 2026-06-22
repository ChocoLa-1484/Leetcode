class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }
    int quickselect(vector<int>& v, int l, int r, int k){
        if (l == r) return v[l];
        int idx = l + rand() % (r - l + 1);
        swap(v[idx], v[r]);
        int pivot = v[r], p = l;
        for (int j = l; j < r; j++)
            if (v[j] < pivot)
                swap(v[p++], v[j]);
        swap(v[p], v[r]);
        if (p == k) return v[p];
        else if (p < k) return quickselect(v, p + 1, r, k);
        else    return quickselect(v, l, p - 1, k);
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + nums.size() - k, nums.end());
        return nums[nums.size() - k];
    }
};