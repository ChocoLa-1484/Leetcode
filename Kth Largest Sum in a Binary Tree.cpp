class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        while (!q.empty()) {
            long long ret = 0;
            for (int n = q.size(); n--;) {
                auto x = q.front();
                q.pop();
                ret += x->val;
                if (x->left)    q.push(x->left);
                if (x->right)   q.push(x->right);
            }
            pq.push(ret);
            if (pq.size() > k) pq.pop();
        }
        if (pq.size() < k)  return -1;
        return pq.top();
    }
};