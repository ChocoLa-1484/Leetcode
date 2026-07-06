class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            if (a[0] == b[0])   return a[1] > b[1];
            return a[0] < b[0];
        });
        int r = -1, ans = intervals.size();
        for (auto i : intervals) {
            if (i[1] <= r)  ans--;
            else    r = i[1];
        }
        return ans;
    }
};