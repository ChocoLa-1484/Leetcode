class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        ranges::sort(candidates);
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, int i) {
            if (target == 0) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n && candidates[j] <= target; j++) {
                path.push_back(candidates[j]);
                target -= candidates[j];
                dfs(j);
                target += candidates[j];
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};