class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        auto inorder = [&](this auto&& inorder, TreeNode* node) {
            if (!node)  return;
            inorder(node->left);
            v.push_back(node->val);
            inorder(node->right);
        };
        inorder(root);
        int n = queries.size();
        vector<vector<int>> ans(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            int q = queries[i];
            auto it = ranges::lower_bound(v, q);
            if (it != end(v) && *it == q)
                ans[i][0] = ans[i][1] = q;
            else {
                ans[i][0] = it == begin(v) ? -1 : *prev(it);
                ans[i][1] = it == end(v) ? -1 : *it;
            }
        }
        return ans;
    }
};