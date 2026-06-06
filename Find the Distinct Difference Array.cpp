class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        short l[51] = {}, r[51] = {};
        short ln = 0, rn = 0;
        for (auto i : nums) {
            if (r[i] == 0)  rn++;
            r[i]++;
        }
        vector<int> ans;
        for (auto i : nums) {
            if (l[i] == 0)  ln++;
            l[i]++;
            r[i]--;
            if (r[i] == 0)  rn--;
            ans.emplace_back(ln - rn);
        }
        return ans;
    }
};