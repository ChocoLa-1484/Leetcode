class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int v1 = cost[0], v2 = cost[1];
        int n = cost.size();
        
        for(int i = 2; i < n; i++) {
            int v = min(v1, v2) + cost[i];
            v1 = v2;
            v2 = v;
        }
        return min(v1, v2);
    }
};