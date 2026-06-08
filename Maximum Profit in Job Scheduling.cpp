class Solution {
public:
    struct job {
        int st, ed, w;
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector <int> dp(n + 1, 0);
        vector <job> v;
        for (int i = 0; i < n; i++) {
            v.emplace_back(job{startTime[i], endTime[i], profit[i]});
        }
        sort(v.begin(), v.end(), [](const job& a, const job& b){
            return a.st < b.st;
        });
        for (int i = n - 1; i >= 0; i--) {
            auto next = lower_bound(v.begin(), v.end(), v[i].ed, [](const job& a, int t){
                return a.st < t;
            }) - v.begin();
            dp[i] = max(dp[i + 1], v[i].w + dp[next]);
        }
        return dp[0];
    }
};