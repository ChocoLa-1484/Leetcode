class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        bitset<1001> bs;
        for (const int i: to_delete)
            bs.set(i);
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> TreeNode*{
            if (!node) return nullptr;
            node->left = dfs(node->left);
            node->right = dfs(node->right);
            if (!bs.test(node->val)) return node;
            if (node->left) ans.push_back(node->left);
            if (node->right) ans.push_back(node->right);
            return nullptr;
        };
        if (dfs(root))  ans.push_back(root);
        return ans;
    }
};