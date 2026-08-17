class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* node) {
            if (!node)   return true;
            if (node->val != root->val)
                return false;
            return dfs(node->left) && dfs(node->right);
        };
        return dfs(root);
    }
};