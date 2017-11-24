class Solution {
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));

        queue<pair<int, int>> q;
        q.push(make_pair(start[0], start[1]));
        vis[start[0]][start[1]] = true;

        while(!q.empty()) {
            int r = q.front().first, c = q.front().second; q.pop();
            for(int i = 0; i < 4; i++) {
                int x, y;
                for(x = r, y = c; x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0; x += dx[i], y += dy[i]);
                switch(i) {
                case 0: y--; break;
                case 1: y++; break;
                case 2: x--; break;
                case 3: x++; break;
                }
                if(x == destination[0] && y == destination[1]) return true;
                if(!vis[x][y]) {
                    vis[x][y] = true;
                    q.push(make_pair(x, y));
                }
            }
        }

        return false;
    }
};
