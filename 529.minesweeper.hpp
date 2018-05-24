class Solution {
    vector<int> moves = {-1, 0, 1};
    vector<pair<int, int>> dirs;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        for(int x: moves)
            for(int y: moves)
                if(!(x == 0 && y == 0))
                    dirs.push_back({x, y});
        int r = click[0], c = click[1];
        if(board[r][c] == 'M') {
            board[r][c] = 'X';
        } else {
            dfs(r, c, board);
        }
        return board;
    }
    void dfs(int r, int c, vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        if(!isValid(r, c, m, n) || board[r][c] != 'E') return;
        int cnt = 0;
        for(auto& dir: dirs) {
            int x = r + dir.first;
            int y = c + dir.second;
            if(isValid(x, y, m, n) && board[x][y] == 'M')
                cnt++;
        }
        if(cnt == 0) {
            board[r][c] = 'B';
            for(auto& dir: dirs) {
                int x = r + dir.first;
                int y = c + dir.second;
                dfs(x, y, board);
            }
        } else {
            board[r][c] = cnt + '0';
        }
    }
    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
};
