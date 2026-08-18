class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        optional<int> prev;
        int t = 0;
        int MAX = 0;
        auto inorder = [&](this auto&& inorder, TreeNode* node) {
            if (!node)  return;
            inorder(node->left);
            if (prev && node->val == *prev) {
                t++;
            } else {
                t = 1;
                prev = node->val;
            }
            if (t == MAX)
                ans.push_back(node->val);
            else if (t > MAX) {
                ans.clear();
                ans.push_back(node->val);
                MAX = t;
            }
            inorder(node->right);
        };
        inorder(root);
        return ans;
    }
};