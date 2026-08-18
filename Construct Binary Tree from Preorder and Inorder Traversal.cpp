class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        auto dfs = [&](this auto&& dfs, int l, int r, int id) -> TreeNode*{
            if (l == r) return nullptr;
            int left_size = mp[preorder[l]] - id;
            TreeNode* left = dfs(l + 1, l + left_size + 1, id);
            TreeNode* right = dfs(l + 1 + left_size, r, id + 1 + left_size);
            return new TreeNode(preorder[l], left, right);
        };
        return dfs(0, n, 0);;
    }
};