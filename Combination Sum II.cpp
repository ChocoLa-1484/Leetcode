class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        dfs(0, v, candidates, target);
        return ans;
    }
    void dfs(int now, vector<int>& v, vector<int>& arr, int target) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        for (int i = now; i < arr.size(); i++) {
            if (i > now && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            v.push_back(arr[i]);
            dfs(i + 1, v, arr, target - arr[i]);
            v.pop_back();
        }
    }
};