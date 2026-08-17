class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        auto dfs = [&](this auto&& dfs, TreeNode* node1, TreeNode* node2) {
            if (!node1 || !node2)   return node1 == node2;
            return (node1->val == node2->val) &&
                   ((dfs(node1->left, node2->right) && dfs(node1->right, node2->left)) ||
                   (dfs(node1->left, node2->left) && dfs(node1->right, node2->right)));
        };
        return dfs(root1, root2);
    }
};
