class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        auto dfs = [&](this auto&& dfs, TreeNode* node, string path) {
            if (!node->left && !node->right) {
                ans.emplace_back(path);
                return;
            }
            if (node->left)
                dfs(node->left, path + "->" + to_string(node->left->val));
            if (node->right)
                dfs(node->right, path + "->" + to_string(node->right->val));
        };
        dfs(root, to_string(root->val));
        return ans;
    }
};