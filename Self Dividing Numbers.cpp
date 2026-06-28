class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int x = i;
            bool ok = 1;
            while (x != 0) {
                int y = x % 10;
                if (y == 0 || (i % y) != 0) {
                    ok = 0;
                    break;
                }
                x /= 10;
            }
            if (ok) ans.push_back(i);
        }
        return ans;
    }
};