#define INF INT_MAX
class Solution {
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(rooms[i][j] == 0) q.push(make_pair(i, j));

        int d = 0;
        while(!q.empty()) {
            int sz = q.size();
            d++;
            while(sz--) {
                auto node = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int x = node.first + dx[i];
                    int y = node.second + dy[i];
                    if(x >= 0 && x < m && y >= 0 && y < n) {
                        if(rooms[x][y] == INF) {
                            rooms[x][y] = d;
                            q.push(make_pair(x, y));
                        }
                    }
                }
            }
        }
    }
};
