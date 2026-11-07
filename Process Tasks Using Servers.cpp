class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> free;
        for (const auto [i, w] : servers | views::enumerate) free.emplace(w, i);
        long long t = 0;
        vector<int> ans(tasks.size());
        for (const auto [i, x] : tasks | views::enumerate) {
            t = max(t, static_cast<long long>(i));
            if (free.empty()) t = busy.top().first;
            while (!busy.empty() && busy.top().first <= t) {
                auto [_, index] = busy.top(); busy.pop();
                free.emplace(servers[index], index);
            }
            auto [weight, index] = free.top(); free.pop();
            ans[i] = index; 
            busy.push({t + x, index});
        }
        return ans;
    }
};