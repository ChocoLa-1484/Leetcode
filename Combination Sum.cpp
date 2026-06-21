class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        dfs(v, candidates, 0, target);
        return ans;
    }
    void dfs(vector<int>& v, vector<int>& arr, int now, int target) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        for (int i = now; i < arr.size(); i++) {
            if (arr[i] > target)    continue;
            v.push_back(arr[i]);
            dfs(v, arr, i, target - arr[i]);
            v.pop_back();
        }
    }
};