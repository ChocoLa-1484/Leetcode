class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> tuple<int, int, int> {
            if (!node)  return {INT_MAX, INT_MIN, 0};
            auto [l_mn, l_mx, l_v] = dfs(node->left);
            auto [r_mn, r_mx, r_v] = dfs(node->right);
            int x = node->val;
            if (x <= l_mx || x >= r_mn) 
                return {INT_MIN, INT_MAX, 0};    
            int v = l_v + x + r_v;
            ans = max(ans, v);
            return {min(x, l_mn), max(x, r_mx), v};
        };
        dfs(root);
        return ans;
    }
};