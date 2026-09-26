class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string_view, string_view> mp;
        mp.reserve(knowledge.size());
        for (const auto& x : knowledge) mp[x[0]] = x[1];
        string ans;
        size_t l;
        ans.reserve(s.size());
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] != '(') {
                ans += s[i];
                continue;
            }
            l = ++i;
            while (s[i] != ')') ++i;
            auto it = mp.find(string_view(s.data() + l, i - l));
            ans += it != mp.end() ? it->second : "?";
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();