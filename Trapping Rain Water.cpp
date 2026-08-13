class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int pre_max = 0, suf_max = 0;
        int ans = 0;
        while (i <= j) {
            pre_max = max(pre_max, height[i]);
            suf_max = max(suf_max, height[j]);
            ans += pre_max < suf_max ? pre_max - height[i++] : suf_max - height[j--];
        }
        return ans;
    }
};