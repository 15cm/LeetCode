#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9) return false;
        for(int i = 0; i < 9; i ++) {
            // Check rows
            auto& row = board[i];
            if(row.size() != 9) return false;
            if(!isValidArea(row)) return false;

            // Check columns
            vector<char> col {
                board[0][i], board[1][i], board[2][i],
                board[3][i], board[4][i], board[5][i],
                board[6][i], board[7][i], board[8][i]};
            if(!isValidArea(col)) return false;

            // Check squares
            int startRow = i / 3 * 3;
            int startCol = (i % 3) * 3;
            vector<char> square {
                board[startRow][startCol], board[startRow][startCol + 1], board[startRow][startCol + 2],
                board[startRow + 1][startCol], board[startRow + 1][startCol + 1], board[startRow + 1][startCol + 2],
                board[startRow + 2][startCol], board[startRow + 2][startCol + 1], board[startRow + 2][startCol + 2]};
            if(!isValidArea(square)) return false;
        }
        return true;
    }
    bool isValidArea(const vector<char>& area) {
        bool marked[10];
        for(int i = 0; i < 10; i ++) marked[i] = false;
        for(auto& c: area) {
            if(c == '.') continue;
            else if(c >= '0' && c <= '9') {
                int index = c - '0';
                if(marked[index]) return false;
                else marked[index] = true;
            } else {
                return false;
            }
        }
        return true;
    }
};
