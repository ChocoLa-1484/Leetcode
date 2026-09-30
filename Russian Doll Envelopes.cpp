class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        ranges::sort(envelopes, {}, [](auto& e) { return pair(e[0], -e[1]); });
        vector<int> v;
        for (const auto& e : envelopes) {
            int x = e[1];
            if (v.empty() || v.back() < x)    v.push_back(x);
            else    *ranges::lower_bound(v, x) = x;
        }
        return v.size();
    }
};