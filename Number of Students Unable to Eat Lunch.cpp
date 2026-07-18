class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int i : students)
            q.push(i);
        for (int i : sandwiches) {
            int times = 0;
            while (q.front() != i) {
                if (times >= q.size())  return q.size();
                int x = q.front();
                q.pop();
                q.push(x);
                times++;
            }
            q.pop();
        }
        return 0;
    }
};