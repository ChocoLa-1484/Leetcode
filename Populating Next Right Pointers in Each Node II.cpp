class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* prev = nullptr;
            for (int n = q.size(); n--;) {
                auto x = q.front();
                q.pop();
                x->next = prev;
                prev = x;
                if (x->right)   q.push(x->right);
                if (x->left)    q.push(x->left);
            }
        }
        return root;
    }
};