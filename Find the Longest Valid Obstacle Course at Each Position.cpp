class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n);
        auto end = obstacles.begin();
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(obstacles.begin(), end, obstacles[i]);
            ans[i] = it - obstacles.begin() + 1;
            *it = obstacles[i];
            if (it == end)  end++;
        }
        return ans;
    }
};