class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)  return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> v;
            for (int n = q.size(); n--;) {
                auto x = q.front();
                q.pop();
                v.push_back(x->val);
                if (x->left)  q.push(x->left);
                if (x->right) q.push(x->right);
            }
            if (ans.size() & 1)
                ranges::reverse(v);
            ans.push_back(move(v));
        }
        return ans;
    }
};