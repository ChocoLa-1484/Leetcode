class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> v(1, 1);
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(v);
            vector<int> tmp(i + 1);
            tmp[0] = tmp.back() = 1;
            for (int j = 0; j < v.size() - 1; j++) {
                tmp[j + 1] = v[j] + v[j + 1];
            }
            v = tmp;
        }
        return ans;
    }
};