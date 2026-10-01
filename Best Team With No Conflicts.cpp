class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {scores[i], ages[i]};
        ranges::sort(v);
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (v[j].second <= v[i].second)
                    dp[i] = max(dp[i], dp[j]);
            dp[i] += v[i].first;
        }
        return ranges::max(dp);
    }
};

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> v(n);
        int u = 0;
        for (int i = 0; i < n; i++) {
            v[i] = {scores[i], ages[i]};
            u = max(u, ages[i]);
        }
        ranges::sort(v);
        vector<int> max_sum(u + 1);
        for (const auto& [score, age] : v) {
            max_sum[i] = ranges::max(max_sum.begin(), max_sum.begin() + age + 1) + score;
        }
        return ranges::max(max_sum);
    }
};

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> v(n);
        int maxAge = 0;
        for (int i = 0; i < n; i++) {
            v[i] = {scores[i], ages[i]};
            maxAge = max(maxAge, ages[i]);
        }
        ranges::sort(v);
        vector<int> bit(maxAge + 1);
        
        auto query = [&](int age) {
            int best = 0;
            while (age > 0) {
                best = max(best, bit[age]);
                age -= age & -age;
            }
            return best;
        };

        auto update = [&](int age, int value) {
            while (age <= maxAge) {
                bit[age] = max(bit[age], value);
                age += age & -age;
            }
        };

        int ans = 0;
        for (const auto& [score, age] : v) {
            int val = query(age) + score;
            ans = max(ans, val);
            update(age, val);
        }
        return ans;
    }
};