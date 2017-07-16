#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int DIRECTION_X[4] = {1, 0, -1, 0};
    const int DIRECTION_Y[4] = {0, 1, 0, -1};
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(dfs(board, vis, i, j, word, 0))
                    return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int x, int y, string& word, int cur) {
        if(board[x][y] == word[cur]) {
            if(cur == word.length() - 1) return true;
        } else {
            return false;
        }
        vis[x][y] = true;
        for(int i = 0; i < 4; i ++) {
            int xNext = x + DIRECTION_X[i];
            int yNext = y + DIRECTION_Y[i];
            if(pointValid(vis, xNext, yNext)
               && dfs(board, vis, xNext, yNext, word, cur + 1)) {
                return true;
            }
        }
        vis[x][y] = false;
        return false;
    }
    bool pointValid(vector<vector<bool>>& vis, int x, int y) {
        return x >= 0 && x < vis.size() && y >= 0 && y < vis[0].size() && !vis[x][y];
    }
};
