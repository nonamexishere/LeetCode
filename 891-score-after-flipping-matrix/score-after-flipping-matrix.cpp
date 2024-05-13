class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) continue;
            for (int j = 0; j < n; ++j) {
                grid[i][j] ^= 1;
            }
        }
        vector<bool> v(n, false);
        for (int j = 0; j < n; ++j) {
            int count = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) count++;
            }
            if (count <= m / 2) v[j] = true;
        }
        for (int j = 0; j < n; ++j) {
            if (v[j]) {
                for (int i = 0; i < m; ++i) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int num = 1;
            for (int j = 1; j < n; ++j) {
                num <<= 1;
                if (grid[i][j] == 1)
                num += 1;
            }
            ans += num;
        }
        return ans;
    }
};