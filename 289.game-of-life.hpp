class Solution {
    const int dx[8] = {0,0,1,1,1,-1,-1,-1};
    const int dy[8] = {1,-1,0,1,-1,0,1,-1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                int cnt = countLives(board, i, j);
                int &b = board[i][j];
                if(b == 1 && (cnt == 2 || cnt == 3)) {
                    b = 3;
                }
                if(b == 0 && cnt == 3) {
                    b = 2;
                }
            }
        for(auto &row: board)
            for(int &b: row)
                b >>= 1;
    }
    int countLives(vector<vector<int>>& board, int r, int c) {
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for(int i = max(r - 1, 0); i <= min(r + 1, m - 1); i++)
            for(int j = max(c - 1, 0); j <= min(c + 1, n - 1); j++) {
                cnt += board[i][j] & 1;
            }
        return cnt - (board[r][c] & 1);
    }
};
