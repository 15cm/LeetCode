class TicTacToe {
    vector<vector<int>> grid;
    int n;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        grid = vector<vector<int>>(n, vector<int>(n));
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        grid[row][col] = player;
        int cnt;
        // row
        cnt = 0;
        for(int i = col; i >= 0; i--) checkCell(row, i, player, cnt);
        for(int i = col + 1; i < n; i++) checkCell(row, i, player, cnt);
        if(cnt == n) return player;
        // col
        cnt = 0;
        for(int i = row; i >= 0; i--) checkCell(i, col, player, cnt);
        for(int i = row + 1; i < n; i++) checkCell(i, col, player, cnt);
        if(cnt == n) return player;
        // main diagonal
        cnt = 0;
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) checkCell(i, j, player, cnt);
        for(int i = row + 1, j = col + 1; i < n && j < n; i++, j++) checkCell(i, j, player, cnt);
        if(cnt == n) return player;
        // back diagonal
        cnt = 0;
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) checkCell(i, j, player, cnt);
        for(int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) checkCell(i, j, player, cnt);
        if(cnt == n) return player;

        return 0;
    }
    void checkCell(int i, int j, int player, int& cnt) {
        if(grid[i][j] == player) cnt++;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
