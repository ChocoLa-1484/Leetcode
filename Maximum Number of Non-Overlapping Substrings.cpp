#define pii pair<int, int>
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        pii pos[26];
        ranges::fill(pos, pii{-1, -1});
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (pos[c].first == -1)   pos[c].first = i;
            pos[c].second = i;
        }
        vector<pii> v;
        for (int i = 0; i < 26; i++) {
            if (pos[i].second == -1)    continue;
            auto [l, r] = pos[i];
            bool ok = true;
            for (int j = l + 1; j < r; j++) {
                int c = s[j] - 'a';
                if (pos[c].first < l) {
                    ok = false;
                    break;
                }
                r = max(r, pos[c].second);
            }
            if (ok) v.emplace_back(r, l);
        }
        ranges::sort(v);
        vector<string> ans;
        int right = -1;
        for (const auto& [r, l] : v) {
            if (l > right) {
                ans.emplace_back(s.substr(l, r - l + 1));
                right = r;
            }
        }
        return ans;
    }
};