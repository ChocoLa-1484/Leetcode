class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        set <char> st;
        int l = 0, r = 0;
        while(r < s.length()) {
            if (st.count(s[r])) st.erase(s[l++]);
            else {
                st.insert(s[r++]);
                if(r - l > ans)  ans = r - l;
            }
        }
        return ans;
    }
};