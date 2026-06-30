class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int freq[3] = {};
        int ans = 0, l = 0;
        for (int r = 0; r < n; r++) {
            freq[s[r] - 'a']++;
            while(freq[0] && freq[1] && freq[2]) {
                ans += n - r;
                freq[s[l] - 'a']--;
                l++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int pos[3] = {-1, -1, -1};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'] = i;
            ans += 1 + min({pos[0], pos[1], pos[2]});
        } 
        return ans;
    }
};