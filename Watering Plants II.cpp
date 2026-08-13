class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int l = 0, r = n - 1;
        int lw = capacityA, rw = capacityB;
        int ans = 0;
        while (l <= r) {
            if (l == r) {
                if (max(lw, rw) < plants[l]) ans++;
                break;
            }
            if (lw < plants[l]) {
                lw = capacityA;
                ans++;
            }
            if (rw < plants[r]) {
                rw = capacityB;
                ans++;
            }
            lw -= plants[l++], rw -= plants[r--];
        }
        return ans;
    }
};