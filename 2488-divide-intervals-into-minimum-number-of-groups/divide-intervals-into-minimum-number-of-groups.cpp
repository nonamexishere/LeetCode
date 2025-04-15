class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int num = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<>> pq;
        num++;
        pq.push(intervals[0][1]);
        int size = intervals.size();
        for (int i = 1; i < size; ++i) {
            if (intervals[i][0] > pq.top()) {
                pq.pop();
                pq.push(intervals[i][1]);
            }
            else {
                num++;
                pq.push(intervals[i][1]);
            }
        }
        return num;
    }
};