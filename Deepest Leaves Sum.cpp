class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while (!q.empty()) {
            ans = 0;
            for (int n = q.size(); n--;) {
                auto x = q.front();
                q.pop();
                ans += x->val;
                if (x->left)    q.push(x->left);
                if (x->right)   q.push(x->right);
            }
        }
        return ans;
    }
};