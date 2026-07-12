class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l <= r) {
            int mid = ((r - l) >> 1) + l;
            if (num % mid == 0 && mid == num / mid)
                return 1;
            if (mid < num / mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return 0;
    }
};