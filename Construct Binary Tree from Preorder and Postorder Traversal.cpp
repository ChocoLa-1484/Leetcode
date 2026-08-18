class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int index[31] = {};
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            index[postorder[i]] = i;
        }
        auto dfs = [&](this auto&& dfs, int l, int r, int st) -> TreeNode* {
            if (l == r) return nullptr;
            if (l + 1 == r) return new TreeNode(preorder[l]);
            int left_size = index[preorder[l + 1]] - st + 1;
            auto left = dfs(l + 1, l + 1 + left_size, st);
            auto right = dfs(l + 1 + left_size, r, st + left_size);
            return new TreeNode(preorder[l], left, right);
        };
        return dfs(0, n, 0);
    }
};