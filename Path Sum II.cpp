class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)  return {};
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, TreeNode* node) {
            if (!node->left && !node->right) {
                int sum = ranges::fold_left(path, 0, plus<>{});
                if (sum == targetSum)
                    ans.emplace_back(path);
                return;
            }
            if (node->left) {
                path.push_back(node->left->val);
                dfs(node->left);
                path.pop_back();
            }
            if (node->right) {
                path.push_back(node->right->val);
                dfs(node->right);
                path.pop_back();
            }
        };
        path.push_back(root->val);
        dfs(root);
        return ans;
    }
};