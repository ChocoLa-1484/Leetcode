class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0, n = events.size(), maxN = 0;
        for (auto& i : events) {
            maxN = max(maxN, i[1]);
        }
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1, j = 0; i <= maxN; i++) {
            if (pq.empty()) {
                if (j == n) break;
                i = events[j][0];
            }
            while (j < n && events[j][0] <= i) {
                pq.emplace(events[j][1]);
                j++;
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};