class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int mx = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    mx = max(mx, dfs(grid, visited, i, j));
                }
            }
        }
        
        return mx;
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }
        
        visited[i][j] = true;
        int left = dfs(grid, visited, i, j - 1);
        int right = dfs(grid, visited, i, j + 1);
        int up = dfs(grid, visited, i - 1, j);
        int down = dfs(grid, visited, i + 1, j);
        
        visited[i][j] = false;
        
        return grid[i][j] + max({left, right, up, down});
    }
};