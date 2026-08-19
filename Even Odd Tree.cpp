class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool even = false;
        q.push(root);
        while (!q.empty()) {
            for (int n = q.size(), prev = (even ? INT_MAX : INT_MIN); n--;) {
                const TreeNode* x = q.front();
                q.pop();
                const int val = x->val;
                if (!even && (!(val & 1) || val <= prev)) return false;
                if (even && ((val & 1) || val >= prev)) return false;
                prev = val;
                if (x->left)    q.push(x->left);
                if (x->right)   q.push(x->right);
            }
            even = !even;
        }
        return true;
    }
};