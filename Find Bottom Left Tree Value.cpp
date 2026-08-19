class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* x;
        while(!q.empty()) {
            x = q.front();
            q.pop();
            if (x->right) q.push(x->right);
            if (x->left)  q.push(x->left);
        }
        return x->val;
    }
};