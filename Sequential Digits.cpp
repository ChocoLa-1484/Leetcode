class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int lLen = to_string(low).length(), hLen = to_string(high).length();
        vector<int> ans;
        for (int i = lLen; i <= hLen; i++) {
            for (int j = 0; j <= 9 - i; j++) {
                int x = stoi(s.substr(j, i));
                if (low <= x && x <= high)
                    ans.push_back(x);
            }
        }
        return ans;
    }
};