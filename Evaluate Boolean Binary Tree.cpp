class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (!root->left)    return root->val;
        auto left = evaluateTree(root->left);
        auto right = evaluateTree(root->right);
        return root->val == 2 ? left | right : left & right;
    }
};