class Solution {
public:
    int lengthOfLastWord(string s) {
        int pre, cur = 0;
        s += ' ';
        for (char ch: s) {
            if (ch != ' ') {
                cur++;
                continue;
            }
            if (cur != 0) {
                pre = cur;
                cur = 0;
            }
        }
        return pre;
    }
};