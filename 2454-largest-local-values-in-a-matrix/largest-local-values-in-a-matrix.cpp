class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 0; i < grid.size() - 2; ++i) {
            for (int j = 0; j < grid[i].size() - 2; ++j) {
                int maxm=INT_MIN;
                maxm = max(grid[i][j], maxm);
                maxm = max(grid[i][j+1], maxm);
                maxm = max(grid[i][j+2], maxm);
                maxm = max(grid[i+1][j], maxm);
                maxm = max(grid[i+1][j+1], maxm);
                maxm = max(grid[i+1][j+2], maxm);
                maxm = max(grid[i+2][j], maxm);
                maxm = max(grid[i+2][j+1], maxm);
                maxm = max(grid[i+2][j+2], maxm);
                tmp.push_back(maxm);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};