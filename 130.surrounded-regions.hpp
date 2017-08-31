class Solution {
public:
    const int steps_r[4] = {0, 1, 0, -1};
    const int steps_c[4] = {1, 0, -1, 0};
    int M, N, m, n;
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        m = board.size(); n = board[0].size();
        M = m + 2; N = n + 2;
        bool mark[M * N] = {false};

        dfs(0, 0, mark, board);
        for(int r = 0; r < m; r++)
            for(int c = 0; c < n; c++)
                if(!mark[encode(r+1,c+1)]) board[r][c] = 'X';
    }
    int encode(int r, int c) {
        return r * N + c;
    }
    bool isValid(int r, int c, bool* mark, vector<vector<char>>& board) {
        if(r >= 0 && r < M && c >= 0 && c < N) {
            if(mark[encode(r, c)]) return false;
            if(r > 0 && r < M - 1 && c > 0 && c < N - 1) {
                return board[r-1][c-1] == 'O';
            }
            return true;
        }
        return false;
    }
    void dfs(int r, int c, bool* mark, vector<vector<char>>& board) {
        mark[encode(r, c)] = true;
        for(int i = 0; i < 4; i++) {
            int row = r + steps_r[i], col = c + steps_c[i];
            if(isValid(row, col, mark, board)) dfs(row, col, mark, board);
        }
    }
};
