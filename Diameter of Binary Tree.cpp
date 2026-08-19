class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* node) {
            if (!node)  return 0;
            auto l = dfs(node->left);
            auto r = dfs(node->right);
            ans = max(ans, l + r);
            return max(l, r) + 1;
        };
        dfs(root);
        return ans;
    }
};