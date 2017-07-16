#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    unordered_set<int> rowRecords[9];
    unordered_set<int> colRecords[9];
    unordered_set<int> gridRecords[9];
    void solveSudoku(vector<vector<char>>& board) {
        for(int r = 0; r < 9; r ++)
            for(int c = 0; c < 9; c ++)
                if(board[r][c] != '.') {
                    setRow(r, board[r][c] - '0');
                    setCol(c, board[r][c] - '0');
                    setGrid(r, c, board[r][c] - '0');
                }
        auto startCoord = nextCoord(0, 0, board);
        for(int i = 1; i <= 9; i ++)
            if(search(startCoord.first, startCoord.second, i, board))
                return;
    }
    bool search(int row, int col, int digit, vector<vector<char>>& board) {
        if(checkRow(row, digit) && checkCol(col, digit) && checkGrid(row, col, digit)) {
            setRow(row, digit);
            setCol(col, digit);
            setGrid(row, col, digit);
            board[row][col] = digit + '0';
            auto coord = nextCoord(row, col, board);
            int r = coord.first;
            int c = coord.second;
            if(r == -1) {
                return true;
            }
            for(int i = 1; i <= 9; i ++) {
                if(search(r, c, i, board)) {
                    return true;
                }
            }
            resetRow(row, digit);
            resetCol(col, digit);
            resetGrid(row, col, digit);
            board[r][c] = '.';
            return false;
        }
        return false;
    }
    pair<int, int> nextCoord(int row, int col, vector<vector<char>>& board) {
        for(int c = col; c < 9; c ++)
            if(board[row][c] == '.')
                return make_pair(row, c);
        for(int r = row + 1; r < 9; r ++)
            for(int c = 0; c < 9; c ++)
                if(board[r][c] == '.')
                    return make_pair(r, c);
        return make_pair(-1, -1);
    }
    int computeGridIndex(int row, int col) {
        return row / 3 * 3 + col / 3;
    }
    bool checkRow(int row, int digit) {
        return rowRecords[row].find(digit) == rowRecords[row].end();
    }
    bool checkCol(int col, int digit) {
        return colRecords[col].find(digit) == colRecords[col].end();
    }
    bool checkGrid(int row, int col, int digit) {
        int index = computeGridIndex(row, col);
        return gridRecords[index].find(digit) == gridRecords[index].end();
    }
    void setRow(int row, int digit) {
        rowRecords[row].insert(digit);
    }
    void setCol(int col, int digit) {
        colRecords[col].insert(digit);
    }
    void setGrid(int row, int col, int digit) {
        int index = computeGridIndex(row, col);
        gridRecords[index].insert(digit);
    }
    void resetRow(int row, int digit) {
        rowRecords[row].erase(digit);
    }
    void resetCol(int col, int digit) {
        colRecords[col].erase(digit);
    }
    void resetGrid(int row, int col, int digit) {
        int index = computeGridIndex(row, col);
        gridRecords[index].erase(digit);
    }
};
