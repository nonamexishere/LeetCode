class Solution {
public:
    int maxElement(queue<int> q) {
        int maxx = INT_MIN;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            maxx = max(maxx, front);
        }
        return maxx;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<vector<int>> ans(size - 2, vector<int>(size - 2));
        for (int i = 0; i < size; ++i) {
            queue<int> q;
            q.push(grid[i][0]);
            q.push(grid[i][1]);
            for (int j = 2; j < size; ++j) {
                q.push(grid[i][j]);
                grid[i][j - 2] = maxElement(q);
                q.pop();
            }
        }
        for (int i = 0; i < size - 2; ++i) {
            queue<int> q;
            q.push(grid[0][i]);
            q.push(grid[1][i]);
            for (int j = 2; j < size; ++j) {
                q.push(grid[j][i]);
                grid[j - 2][i] = maxElement(q);
                q.pop();
            }
        }
        for (int i = 0; i < size - 2; ++i) {
            for (int j = 0; j < size - 2; ++j) {
                ans[i][j] = grid[i][j];
            }
        }
        return ans;
    }
};