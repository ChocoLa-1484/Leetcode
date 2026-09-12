class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> pair<int, int> {
            if (!node)  return {0, 0};
            auto [lSum, lN] = dfs(node->left);
            auto [rSum, rN] = dfs(node->right);
            int sum = lSum + rSum + node->val;
            int n = lN + rN + 1;
            if (sum / n == node->val)   ans++;
            return {sum, n};
        };
        dfs(root);
        return ans;
    }
};