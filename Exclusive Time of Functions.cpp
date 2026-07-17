class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prev = -1;
        for (const string& s : logs) {
            stringstream ss(s);
            string initid, type, inittimestamp;
            
            getline(ss, initid, ':');
            getline(ss, type, ':');
            getline(ss, inittimestamp, ':');
            
            int id = stoi(initid);
            int t = stoi(inittimestamp);

            if (type[0] == 's') {
                if (!st.empty())    ans[st.top()] += t - prev;
                st.push(id);
                prev = t;
            }
            if (type[0] == 'e') {
                ans[st.top()] += t - prev + 1;
                st.pop();
                prev = t + 1;
            }
        }
        return ans;
    }
};