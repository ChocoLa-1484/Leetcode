class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int x = root->val;
        return (x < high ? rangeSumBST(root->right, low, high) : 0) + 
               (x > low ? rangeSumBST(root->left, low, high) : 0) + 
               (low <= x && x <= high ? x : 0);
    }
};