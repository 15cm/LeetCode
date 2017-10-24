class Solution {
    const int dx[8] = {0,0,1,1,1,-1,-1,-1};
    const int dy[8] = {1,-1,0,1,-1,0,1,-1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int cnt = 0;
                for(int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 && x < m && y >= 0 && y < n) {
                        if(board[x][y] == 1 || board[x][y] == 3)
                            cnt++;
                    }
                }
                if(board[i][j] == 0) {
                    if(cnt == 3)
                        board[i][j] = 2;
                } else {
                    if(cnt < 2 || cnt > 3)
                        board[i][j] = 3;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 2)
                    board[i][j] = 1;
                else if(board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
};
