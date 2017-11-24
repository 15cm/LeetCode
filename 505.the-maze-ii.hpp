class Solution {
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));

        queue<pair<int, int>> q;
        q.push(make_pair(start[0], start[1]));
        dis[start[0]][start[1]] = 0;

        while(!q.empty()) {
            int r = q.front().first, c = q.front().second; q.pop();
            for(int i = 0; i < 4; i++) {
                int d = -1;
                int x, y;
                for(x = r, y = c; x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0; x += dx[i], y += dy[i])
                    d++;
                switch(i) {
                case 0: y--; break;
                case 1: y++; break;
                case 2: x--; break;
                case 3: x++; break;
                }
                if(dis[x][y] == -1 || dis[r][c] + d < dis[x][y]) {
                    dis[x][y] = dis[r][c] + d;
                    q.push(make_pair(x, y));
                }
            }
        }

        return dis[destination[0]][destination[1]];
    }
};
