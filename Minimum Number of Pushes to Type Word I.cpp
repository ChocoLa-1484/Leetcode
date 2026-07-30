class Solution {
public:
    int minimumPushes(string word) {
        int x = word.length();
        return x + max(0, x - 8) + max(0, x - 16) + max(0, x - 24);
    }
};