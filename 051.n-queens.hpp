#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        int state[n];
        search(state, 0, n, ans);
        return ans;
    }
    void search(int state[], int row, int n, vector<vector<string>>& ans) {
        if(row == n) {
            vector<string> tmp(n, string(n, '.'));
            for(int r = 0; r < n; r ++) {
                tmp[r][state[r]] = 'Q';
            }
            ans.push_back(tmp);
            return;
        }
        for(int col = 0; col < n; col ++) {
            state[row] = col;
            bool ok = true;
            for(int r = 0; r < row; r ++) {
                if(state[r] == col || r - state[r] == row - state[row] || r + state[r] == row + state[row]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                search(state, row + 1, n, ans);
            }
        }
    }
};
