class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int n = tickets.size();
        for (int i = 0; i < n; i++)
            q.push(i);
        int ans = 0;
        while (!q.empty()) {
            int x = q.front();
            tickets[x]--;
            ans++;
            if (x == k && tickets[x] == 0)
                return ans;
            if (tickets[x] > 0)
                q.push(x);
            q.pop();
        }
        return ans;
    }
};