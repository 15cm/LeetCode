class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int n = board.size();
        vector<int> rows(n), cols(n);
        int diag = 0, anti_diag = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(board[i][j] == ' ') continue;
                int to_add = (board[i][j] == 'X' ? 1 : -1);
                rows[i] += to_add;
                cols[j] += to_add;
                if(i == j) {
                    diag += to_add;
                }
                if(i + j == n - 1) {
                    anti_diag += to_add;
                }
                cnt += to_add;
            }
        int x_cnt = (diag == n) + (anti_diag == n), o_cnt = (diag == -n) + (anti_diag == -n);
        int x_rows_cnt = 0, x_cols_cnt = 0;
        for(int i = 0; i < n; i++) {
            if(rows[i] == n) {
                x_cnt++;
                x_rows_cnt++;
            }
            if(rows[i] == -n) o_cnt++;
            if(cols[i] == n) {
                x_cnt++;
                x_cols_cnt++;
            }
            if(cols[i] == -n) o_cnt++;
        }
        if(cnt < 0 || cnt > 1) return false;
        if(o_cnt >= 2) return false;
        else if(o_cnt == 1) {
            return cnt == 0 && x_cnt == 0;
        } else {
            if(x_cnt > 0) {
                return cnt == 1 && x_rows_cnt < 2 && x_cols_cnt < 2;;
            } else {
                return true;
            }
        }
    }
};
