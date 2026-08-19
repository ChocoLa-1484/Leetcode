class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans = nullptr;
        int mx = -1;
        auto dfs = [&](this auto&& dfs, TreeNode* node, int depth) {
            if (!node) {
                mx = max(mx, depth);
                return depth;
            }
            auto left = dfs(node->left, depth + 1);
            auto right = dfs(node->right, depth + 1);
            if (left == right && left == mx)  ans = node;
            return max(left, right);
        };
        dfs(root, 0);
        return ans;
    }
};