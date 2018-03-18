#define H heightMap

struct Cell {
    int r, c, h;
    Cell(int r, int c, int h): r(r), c(c), h(h) {}
    bool operator < (const Cell& c) const {
        return h > c.h;
    }
};

class Solution {
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(H.empty() || H[0].empty()) return 0;
        int m = H.size(), n = H[0].size();

        bool vis[m][n] = {{false}};
        priority_queue<Cell> pq;
        for(int i = 0; i < m; i++) {
            pq.push(Cell(i, 0, H[i][0]));
            pq.push(Cell(i, n-1, H[i][n-1]));
            vis[i][0] = vis[i][n-1] = true;
        }
        for(int j = 0; j < n; j++) {
            pq.push(Cell(0, j, H[0][j]));
            pq.push(Cell(m-1, j, H[m-1][j]));
            vis[0][j] = vis[m-1][j] = true;
        }

        int ans = 0;
        while(!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            for(auto dir: dirs) {
                int r = cell.r + dir[0];
                int c = cell.c + dir[1];
                if(r > 0 && r < m-1 && c > 0 && c < n-1 && !vis[r][c]) {
                    vis[r][c] = true;
                    ans += max(0, cell.h - H[r][c]);
                    pq.push(Cell(r, c, max(cell.h, H[r][c])));
                }
            }
        }
        return ans;
    }
};
