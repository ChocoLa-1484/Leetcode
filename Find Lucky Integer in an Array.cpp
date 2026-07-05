class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        int ans = -1;
        auto lucky = freq | views::filter([](auto const& p) {
            return p.first == p.second;
        });
        for (auto&& [k, v] : lucky)
            ans = max(ans, k);
        return ans;
    }
};