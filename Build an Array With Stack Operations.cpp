class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int cur = 0, m = target.size();
        for (int i = 1; i <= n; i++) {
            ans.emplace_back("Push");
            if (i != target[cur])
                ans.emplace_back("Pop");
            else if (++cur == m) 
                break;
        }
        return ans;
    }
};