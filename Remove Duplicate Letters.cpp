class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        bitset<26> used;

        for (char c : s)
            cnt[c - 'a']++;

        string st = "";
        for (char c : s) {
            cnt[c - 'a']--;
            if (used[c - 'a'])
                continue;
            while (!st.empty() && st.back() > c && cnt[st.back() - 'a'] > 0) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(c);
            used[c - 'a'] = true;
        }

        return st;
    }
};