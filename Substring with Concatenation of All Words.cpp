class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        vector<int> res;
        int len = words[0].length(), n = words.size();
        for (auto i : words)    cnt[i]++;
        for (int offset = 0; offset < len; offset++) {
            unordered_map<string, int> seen;
            int start = offset, count = 0;
            for (int end = start; end + len <= s.length(); end += len) {
                string sub = s.substr(end, len);
                if (!cnt.count(sub)) {
                    seen.clear();
                    count = 0;
                    start = end + len;
                    continue;
                }
                seen[sub]++;
                count++;
                while (seen[sub] > cnt[sub]) {
                    string x = s.substr(start, len);
                    seen[x]--;
                    count--;
                    start += len;
                }
                if (count == n) res.push_back(start);
            }
        }
        return res;
    }
};