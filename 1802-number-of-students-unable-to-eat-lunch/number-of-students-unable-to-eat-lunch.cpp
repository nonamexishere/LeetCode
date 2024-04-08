class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> s;
        for (int st : students) q.push(st);
        for (auto it = sandwiches.rbegin(); it != sandwiches.rend(); it++) s.push(*it);
        int counter = 0;
        while (counter < students.size() && !q.empty()) {
            if (q.front() == s.top()) {
                q.pop();
                s.pop();
                counter = 0;
            }
            else {
                q.push(q.front());
                q.pop();
                counter++;
            }
        }
        return q.size();
    }
};