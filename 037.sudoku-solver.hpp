typedef vector<char> VC;
typedef vector<VC> VVC;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        backTrack(0, 0, board);
    }
    bool backTrack(int x, int y, VVC& board) {
        int m = board.size(), n = board[0].size();
        if(x == m) return true;
        int new_x, new_y;
        if(y == n - 1) {
            new_x = x + 1;
            new_y = 0;
        } else {
            new_x = x;
            new_y = y + 1;
        }
        if(board[x][y] == '.') {
            for(int i = 1; i <= 9; i++) {
                board[x][y] = '0' + i;
                if(check(x, y, board) && backTrack(new_x, new_y, board))
                    return true;
            }
            board[x][y] = '.';
        } else {
            if(check(x, y, board) && backTrack(new_x, new_y, board))
                return true;
        }
        return false;
    }
    bool check(int x, int y, VVC& board) {
        for(int i = 0; i < 9; i++) {
            if(i != x && board[i][y] == board[x][y]) return false;
            if(i != y && board[x][i] == board[x][y]) return false;
            int x2 = x / 3 * 3 + i / 3, y2 = y / 3 * 3 + i % 3;
            if(x2 != x && y2 != y && board[x2][y2] == board[x][y]) return false;
        }
        return true;
    }
};
