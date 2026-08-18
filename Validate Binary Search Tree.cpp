class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto check = [&](this auto&& check, TreeNode* node, long long l = LLONG_MIN, long long r = LLONG_MAX) {
            if (!node)  return true;
            long long x = node->val;
            return l < x && x < r && check(node->left, l, x) && check(node->right, x, r);
        };
        return check(root);
    }
};