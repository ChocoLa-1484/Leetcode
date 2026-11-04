class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN, sell = 0;
        for (auto i : prices) {
            buy = max(buy, sell - i);
            sell = max(sell, buy + i - fee);
        }
        return sell;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f0 = 0, f1 = INT_MIN;
        for (const int x : prices) {
            int new_f0 = max(f0, f1 + x);
            f1 = max(f1, f0 - x);
            f0 = new_f0;
        }
        return f0;
    }
};