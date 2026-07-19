class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        int n = target.size();
        for (int i : target) {
            pq.push(i);
            sum += i;
        }
        while (1) {
            int x = pq.top();
            pq.pop();
            long long rest = sum - x;
            if (x == 1 || rest == 1) return true;
            if (x <= rest || rest == 0)  return false;
            int tmp = x % rest;
            if (tmp == 0)   return false;
            pq.push(tmp);
            sum = rest + tmp;
        }
        return true;
    }
};