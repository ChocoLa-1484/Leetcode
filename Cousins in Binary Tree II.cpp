class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        vector<TreeNode*> q = {root};
        while (!q.empty()) {
            vector<TreeNode*> v;
            int sum = 0;
            for (const auto x : q) {
                if (x->left) {
                    v.push_back(x->left);
                    sum += x->left->val;
                }
                if (x->right) {
                    v.push_back(x->right);
                    sum += x->right->val;
                }
            }
            for (auto x : q) {
                int tmp = (x->left ? x->left->val : 0) +
                          (x->right ? x->right->val : 0);
                if (x->left) x->left->val = sum - tmp;
                if (x->right) x->right->val = sum - tmp;
            }
            q = move(v);
        }
        return root;
    }
};