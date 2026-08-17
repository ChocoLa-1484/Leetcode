class Solution {
public:
    int get_height(TreeNode* root) {
        if (!root)  return 0;
        int l_height = get_height(root->left);
        if (l_height == -1)
            return -1;
        int r_height = get_height(root->right);
        if (r_height == -1 || abs(l_height - r_height) > 1)
            return -1;
        return max(l_height, r_height) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1;
    }
};