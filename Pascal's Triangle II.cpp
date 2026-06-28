class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(1, 1);
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> tmp(i + 1);
            tmp[0] = tmp.back() = 1;
            for (int j = 0; j < v.size() - 1; j++) {
                tmp[j + 1] = v[j] + v[j + 1];
            }
            v = tmp;
        }
        return v;
    }
};