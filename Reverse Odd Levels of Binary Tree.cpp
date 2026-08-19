class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root)  return {};
        queue<TreeNode*> q;
        q.push(root);
        bool even = false;
        while (!q.empty()) {
            vector<TreeNode*> v;
            for (int n = q.size(); n--;) {
                auto x = q.front();
                q.pop();
                if(even) v.push_back(x);
                if (x->left)    q.push(x->left);
                if (x->right)   q.push(x->right);
            }
            for (int i = 0; i < v.size() / 2; i++)
                swap(v[i]->val, v[v.size() - i - 1]->val);
            even ^= 1;
        }
        return root;
    }
};