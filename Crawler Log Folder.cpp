class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> s;
        for(auto& i: logs) {
            if (i == "../") {
                if(!s.empty())  s.pop();
            } else if(i[0] != '.')  s.push('1');
        }
        return s.size();
    }
};