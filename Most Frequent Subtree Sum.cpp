class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        int mx = -1;
        auto dfs = [&](this auto&& dfs, TreeNode* node) {
            if (!node)  return 0;
            node->val += dfs(node->left) + dfs(node->right);
            mp[node->val]++;
            mx = max(mx, mp[node->val]);
            return node->val;
        };
        dfs(root);
        vector<int> ans;
        for (const auto& [x, t] : mp)
            if (t == mx)
                ans.push_back(x);
        return ans;
    }
};