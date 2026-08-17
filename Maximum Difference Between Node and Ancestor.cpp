class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return find(root)[2];
    }
    array<int, 3> find(TreeNode* node) {
        if (!node)   return {INT_MAX, INT_MIN, 0};
        auto [x, y, a1] = find(node->left);
        auto [w, z, a2] = find(node->right);
        int mn = min({x, w, node->val}), mx = max({y, z, node->val});
        return {mn, mx, max({a1, a2, node->val - mn, mx - node->val})};
    }
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
    int dfs(TreeNode* node, int mn, int mx) {
        if (!node) return mx - mn;
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        return max(dfs(node->left, mn, mx), dfs(node->right, mn, mx));
    }
};