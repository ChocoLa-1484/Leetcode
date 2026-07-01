class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size(), sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += (word[i] != word[i + 1]);
        return n - sum;
    }
};