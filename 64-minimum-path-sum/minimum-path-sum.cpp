class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i != 0 && j != 0) {
                    grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
                    continue;
                }
                if (i == 0 && j != 0) {
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                    continue;
                }
                if (j == 0 && i != 0) {
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                }
            } 
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};