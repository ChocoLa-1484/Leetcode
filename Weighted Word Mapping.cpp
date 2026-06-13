class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (auto s : words) {
            int sum = 0;
            for (auto i : s) {
                sum += weights[i - 'a'];
            }
            ans += 'z' - sum % 26;
        }
        return ans;
    }
};