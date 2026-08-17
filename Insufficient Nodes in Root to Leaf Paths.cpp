class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root)  return nullptr;
        limit -= root->val; 
        if (!root->left && !root->right)
            return limit > 0 ? nullptr : root;
        root->left = sufficientSubset(root->left, limit);
        root->right = sufficientSubset(root->right, limit);
        return !root->left && !root->right ? nullptr : root;
    }
};