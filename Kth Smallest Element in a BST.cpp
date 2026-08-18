class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int now = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> optional<int> {
            if (!node)  return nullopt;
            if (auto l = dfs(node->left)) 
                return *l;
            if (--k == 0) return node->val;
            return dfs(node->right);
        };
        return *dfs(root);
    }
};