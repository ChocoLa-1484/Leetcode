class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bitset<105> bs;
        for (const int x : nums)
            bs.set(x);
        for (int i = 1; i < 105; i++) {
            if (k * i >= 105 || !bs.test(k * i))    return k * i;
        }
        return 1;
    }
};