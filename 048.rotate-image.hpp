#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int n = matrix.size();
        for(int i = 0; i < n; i ++) 
            for(int j = i + 1; j < n; j ++)
                swap(i, j, j, i, matrix);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n/2; j ++)
                swap(i, j, i, n-1-j, matrix);
    }

    void swap(int r1, int c1, int r2, int c2, vector<vector<int>>& matrix) {
        int tmp = matrix[r1][c1];
        matrix[r1][c1]  = matrix[r2][c2];
        matrix[r2][c2] = tmp;
    }
};
