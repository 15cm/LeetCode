class Solution {
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();

        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 ) {
                            ans++;
                        }
                    }
                }
            }
        return ans;
    }
};
