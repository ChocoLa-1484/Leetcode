class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        return ((root->val < low || root->val > high) ? 0 : root->val) + 
                rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};