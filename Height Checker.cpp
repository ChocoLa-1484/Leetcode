class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int counts[101] = {};
        for(auto i : heights) {
            counts[i]++;
        }
        int l = 0, ans = 0, n = heights.size();
        for (int i = 1; i <= 100 && l < n; i++) {
            while (counts[i] != 0) {
                counts[i]--;
                if (heights[l++] != i)  ans++;
            }
        }
        return ans;
    }
};