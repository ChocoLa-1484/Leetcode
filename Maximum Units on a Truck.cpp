class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b) {
            if (a[1] == b[1])   return a[0] < b[0];
            return a[1] > b[1];
        });
        int n = boxTypes.size(), ans = 0;
        for (auto b : boxTypes) {
            if (b[0] > truckSize)   {
                ans += truckSize * b[1];
                break;
            }
            ans += b[1] * b[0];
            truckSize -= b[0];
        }
        return ans;
    }
};

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int freq[1005] = {};
        int maxN = -1;
        for (const auto& b : boxTypes) {
            freq[b[1]] += b[0];
            maxN = max(maxN, b[1]);
        }
        int n = boxTypes.size(), ans = 0;
        for (int i = maxN; i >= 0; i--) {
            if (freq[i] == 0)   continue;
            if (freq[i] > truckSize)   {
                ans += truckSize * i;
                break;
            }
            ans += i * freq[i];
            truckSize -= freq[i];
        }
        return ans;
    }
};