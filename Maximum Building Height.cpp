class Solution {
public:
    int maxBuilding(int num, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        int n = restrictions.size();
        for (int i = 1; i < n; i++) 
            restrictions[i][1] = cap(restrictions[i - 1], restrictions[i]);
        for (int i = n - 2; i >= 0; i--) 
            restrictions[i][1] = cap(restrictions[i + 1], restrictions[i]);
        int MAX = 0;
        for (int i = 1; i < n; i++) 
            MAX = max(MAX, peak(restrictions[i - 1], restrictions[i]));
        return max(MAX, restrictions[n - 1][1] + num - restrictions[n - 1][0]);
    }

    int cap(vector<int> l, vector<int> r) {
        return min(r[1], l[1] + abs(r[0] - l[0]));
    }

    int peak(vector<int> l, vector<int> r) {
        return (l[1] + r[1] + r[0] - l[0]) >> 1;
    }
};