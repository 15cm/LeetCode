class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(0, 0, board);
    }
    bool dfs(int r, int c, vector<vector<char>> &B) {
        int m = B.size(), n = B[0].size();
        if(r == m) return true;
        if(c == n) return dfs(r + 1, 0, B);
        if(B[r][c] != '.') return dfs(r, c + 1, B);
        for(int i = 1; i <= 9; i++) {
            char d = i + '0';
            if(check(r, c, d, B)) {
                B[r][c] = d;
                if(dfs(r, c + 1, B))
                    return true;;
                B[r][c] = '.';
            }
        }
        return false;
    }
    bool check(int r, int c, char d, vector<vector<char>> &B) {
        int m = B.size(), n = B[0].size();
        for(int i = 0; i < m; i++)
            if(i != r && B[i][c] == d) return false;
        for(int j = 0; j < n; j++)
            if(j != c && B[r][j] == d) return false;
        int start_r = r /3 * 3, start_c = c / 3 * 3;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) {
                int x = start_r + i, y = start_c + j;
                if(!(x == r && y == c) && B[x][y] == d)
                    return false;
            }
        return true;
    }
};
