class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)  return s;
        vector<string> v;
        v.resize(numRows);
        int j = 0;
        bool add = true;
        for (auto i : s) {
            v[j] += i;
            add ? j++ : j--;
            if (j == numRows - 1)   add = !add;
            else if (j == 0)   add = !add;
        }
        string ans = "";
        for(auto row : v) {
            ans += row;
        }
        return ans;
    }
};