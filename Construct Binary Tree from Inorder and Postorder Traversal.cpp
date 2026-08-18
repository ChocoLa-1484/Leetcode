class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index[6001] = {};
        int n = inorder.size();
        constexpr static int OFFSET = 3000;
        for (int i = 0; i < n; i++) {
            index[inorder[i] + OFFSET] = i;
        }
        auto dfs = [&](this auto&& dfs, int l, int r, int in_id) -> TreeNode* {
            if (l == r) return nullptr;
            int root_val = postorder[r - 1];
            int left_size = index[root_val + OFFSET] - in_id;
            auto left = dfs(l, l + left_size, in_id);
            auto right = dfs(l + left_size, r - 1, in_id + left_size + 1);
            return new TreeNode(root_val, left, right);
        };
        return dfs(0, n, 0);
    }
};