class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> d(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'E') {
                    for(int k = i + 1; k < m; k++)
                        if(grid[k][j] == '0') d[k][j]++;
                        else if(grid[k][j] == 'W') break;
                    for(int k = i - 1; k >= 0; k--)
                        if(grid[k][j] == '0') d[k][j]++;
                        else if(grid[k][j] == 'W') break;
                    for(int k = j + 1; k < n; k++)
                        if(grid[i][k] == '0') d[i][k]++;
                        else if(grid[i][k] == 'W') break;
                    for(int k = j - 1; k >= 0; k--)
                        if(grid[i][k] == '0') d[i][k]++;
                        else if(grid[i][k] == 'W') break;
                }
            }

        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans = max(ans, d[i][j]);
        return ans;
    }
};
