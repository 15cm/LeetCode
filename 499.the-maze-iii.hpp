#define INF INT_MAX
struct Node {
    int r, c, d;
    Node(int r, int c, int d):r(r), c(c), d(d) {}
    bool operator < (const Node &rhs) const {
        return d > rhs.d;
    }
};

class Solution {
    const vector<string> dirs = {"u", "d", "l", "r"};
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        if(maze.empty() || maze[0].empty() || ball == hole) return 0;
        int m = maze.size(), n = maze[0].size();
        int hx = hole[0], hy = hole[1];
        vector<vector<pair<int, string>>> dis(m, vector<pair<int, string>>(n, {INF, ""}));
        Node start(ball[0], ball[1], 0);
        dis[start.r][start.c].first = start.d;
        priority_queue<Node> pq;
        pq.push(start);

        while(!pq.empty()) {
            auto node = pq.top(); pq.pop();
            for(int i = 0; i < 4; i++) {
                int x = node.r, y = node.c, d = 0;
                switch(i) {
                case 0:
                    for(; x >= 1 && !(x == hx && y == hy) && maze[x-1][y] == 0; x--) d++;
                    break;
                case 1:
                    for(; x < m - 1 && !(x == hx && y == hy) && maze[x+1][y] == 0; x++) d++;
                    break;
                case 2:
                    for(; y >= 1 && !(x == hx && y == hy) && maze[x][y-1] == 0; y--) d++;
                    break;
                case 3:
                    for(; y < n - 1 && !( x == hx && y == hy) && maze[x][y+1] == 0; y++) d++;
                    break;
                }
                auto& disPr = dis[x][y];
                int new_d = d + node.d;
                string new_s = dis[node.r][node.c].second + dirs[i];
                if(new_d < disPr.first || new_d == disPr.first && new_s < disPr.second) {
                    disPr = {new_d, new_s};
                    pq.push(Node(x, y, new_d));
                }
            }
        }
        auto& ansPr = dis[hx][hy];
        return ansPr.first == INF ? "impossible" : ansPr.second;
    }
};
