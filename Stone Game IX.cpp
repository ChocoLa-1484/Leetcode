class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};
        for (const int x : stones) 
            cnt[x % 3]++;
        if (cnt[0] % 2 == 0)
            return cnt[1] && cnt[2] ;
        return abs(cnt[1] - cnt[2]) > 2;
    }
};