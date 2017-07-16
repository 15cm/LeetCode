#include <vector>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> visit(3, vector<bool>(2 * n - 1, false));
        int ans = 0;
        search(0, n, visit, ans);
        return ans;
    }
    void search(int row, int n, vector<vector<bool>>& visit, int& ans) {
        if(row == n) {
            ans++;
            return;
        }
        for(int col = 0; col < n; col ++) {
            int diagonalIndex = col - row + n;
            int counterDiagonalIndex = col + row;
            if(!(visit[0][col] || visit[1][diagonalIndex] || visit[2][counterDiagonalIndex])) {
                visit[0][col] = visit[1][diagonalIndex] = visit[2][counterDiagonalIndex] = true;
                search(row + 1, n, visit, ans);
                visit[0][col] = visit[1][diagonalIndex] = visit[2][counterDiagonalIndex] = false;
            }
        }
    }
};
