auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int, int>> s;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int counter = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                if (grid[i][j] == '1') {
                    s.push({i, j});
                    visited[i][j] = true;
                    counter++;
                    while(!s.empty()) {
                        int tf = s.top().first;
                        int ts = s.top().second;
                        s.pop();
                        if (tf > 0 && !visited[tf - 1][ts] && grid[tf - 1][ts] == '1') {s.push({tf - 1, ts}); visited[tf - 1][ts] = true;}
                        if (tf < grid.size() - 1 && !visited[tf + 1][ts] && grid[tf + 1][ts] == '1') {s.push({tf + 1, ts}); visited[tf + 1][ts] = true;}
                        if (ts > 0 && !visited[tf][ts - 1] && grid[tf][ts - 1] == '1') {s.push({tf, ts - 1}); visited[tf][ts - 1] = true;}
                        if (ts < grid[0].size() - 1 && !visited[tf][ts + 1] && grid[tf][ts + 1] == '1') {s.push({tf, ts + 1}); visited[tf][ts + 1] = true;}
                    }
                }
            }
        }
        return counter;
    }
};