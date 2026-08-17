class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        [&](this auto&& dfs, TreeNode* node, int depth){
            if (!node)   return;
            if (depth == ans.size()) {
                ans.push_back(node->val);
            }
            dfs(node->right, depth + 1);
            dfs(node->left, depth + 1);
        }(root, 0);
        return ans;
    }
};