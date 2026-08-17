class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    void invert(TreeNode* node) {
        if (!node)  return;
        invert(node->left);
        invert(node->right);
        swap(node->left, node->right);
    }
};