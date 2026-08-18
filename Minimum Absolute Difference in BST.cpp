class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        optional<int> prev;
        auto dfs = [&](this auto&& dfs, TreeNode* node) {
            if (!node)  return;
            dfs(node->left);
            if (prev) 
                ans = min(ans, node->val - *prev);
            prev = node->val;
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};