class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int st : students) q.push(st);
        int counter = 0;
        int i = 0;
        while (counter < students.size() && !q.empty()) {
            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
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