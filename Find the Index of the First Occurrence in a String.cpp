class Solution {

public:
    int strStr(string haystack, string needle) {
        vector <int> fail = build(needle);
        return match(haystack, needle, fail);
    }
private:
    vector<int> build(string &t) {
        vector<int> F(t.size());
        F[0] = -1;
        for (int i = 1, pos = -1 ; i < t.size() ; i++) {
            while (~pos && t[i] != t[pos + 1])  pos = F[pos];
            if (t[i] == t[pos + 1]) pos++;
            F[i] = pos;
        }
        return F;
    }
    int match(string &s, string &t, vector<int> &f) {
        for (int i = 0, pos = -1 ; i < s.size() ; i++) {
            while (~pos && s[i] != t[pos + 1])
                pos = f[pos];
            if (s[i] == t[pos + 1]) pos++;
            if (pos + 1 == (int)t.size()) {
                return i - pos;
                pos = f[pos];
            }
        }
        return -1;
    }
};