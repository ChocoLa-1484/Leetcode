class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = min(citations[0], n), r = min(citations.back(), n) + 1;
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            (citations[n - mid] >= mid ? l : r) = mid;
        }
        return l;
    }
};