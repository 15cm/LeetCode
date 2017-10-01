typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;

class Solution {
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        VVB vis(m, VB(n));
        bool ans = false;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                vis[i][j] = true;
                ans |= dfs(i, j, 0, word, vis, board);
                vis[i][j] = false;
            }
        return ans;
    }
    bool dfs(int x, int y, int cur, string& word, VVB& vis, VVC& board) {
        int m = board.size(), n = board[0].size();
        if(cur == word.size()) return false;
        if(cur == word.size() - 1 && board[x][y] == word[cur]) return true;
        if(board[x][y] != word[cur]) return false;
        for(int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 && newx < m && newy >= 0 && newy < n && !vis[newx][newy]) {
                vis[newx][newy] = true;
                if(dfs(newx, newy, cur + 1, word, vis, board)) return true;
                vis[newx][newy] = false;
            }
        }
        return false;
    }
};
