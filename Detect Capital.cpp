class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int sm = 0;
        for (char c : word)
            if (islower(c)) sm++;
        return (sm == n || sm == 0 || (isupper(word[0]) && sm == n - 1));
    }
};