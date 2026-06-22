class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26] = {};
        for (auto i : text) {
            cnt[i - 'a']++;
        }
        return min({cnt[1], cnt[0], cnt['n' - 'a'], cnt['l' - 'a'] / 2,
                    cnt['o' - 'a'] / 2});
    }
};