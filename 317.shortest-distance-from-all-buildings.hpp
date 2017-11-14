class Solution {
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return -1;
        int m = grid.size(), n = grid[0].size();
        int num = 0;
        vector<vector<int>> dis(m, vector<int>(n));
        vector<vector<int>> cnt(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    vector<vector<bool>> vis(m, vector<bool> (n));
                    q.push(make_pair(i, j));
                    int d = 0;
                    while(!q.empty()) {
                        d++;
                        int sz = q.size();
                        while(sz--) {
                            auto pr = q.front(); q.pop();
                            int r = pr.first;
                            int c = pr.second;
                            for(int i = 0; i < 4; i++) {
                                int x = r + dx[i];
                                int y = c + dy[i];
                                if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !vis[x][y]) {
                                    vis[x][y] = true;
                                    dis[x][y] += d;
                                    cnt[x][y]++;
                                    q.push(make_pair(x,y));
                                }
                            }
                        }
                    }
                    num++;
                }
            }
        if(num == 0) return -1;
        int ans = INT_MAX;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(cnt[i][j] == num && grid[i][j] == 0 && dis[i][j] < ans)
                    ans = dis[i][j];
            }
        return ans == INT_MAX ? -1 : ans;
    }
};
