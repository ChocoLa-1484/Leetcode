class Solution {
private:
    unordered_map<int, int> mp{};
    int index = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, n - 1);;
    }
private:
    TreeNode* build(vector<int>& preorder, int l, int r) {
        if (l > r)  return nullptr;
        int rootVal = preorder[index++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];

        root->left = build(preorder, l, mid - 1);
        root->right = build(preorder, mid + 1, r);

        return root;
    }
};