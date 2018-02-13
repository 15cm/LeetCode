class NumMatrix {
    vector<vector<int>> A, C;
    int m, n;
public:
    NumMatrix(vector<vector<int>> matrix) {
        m = matrix.size(), n = (m == 0 ? 0 : matrix[0].size());
        A = vector<vector<int>>(m, vector<int>(n));
        C = vector<vector<int>>(m+1, vector<int>(n+1));
        for(int i = 0; i < m ; i++)
            for(int j = 0; j < n; j++)
                update(i, j, matrix[i][j]);
    }
    
    void update(int row, int col, int val) {
        int x = val - A[row][col];
        A[row][col] = val;
        row++; col++;
        for(int i = row; i <= m; i += (i & -i)) {
            for(int j = col; j <= n; j += (j & -j)) {
                C[i][j] += x;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1--; col1--;
        return query(row2, col2) - query(row1, col2) - query(row2, col1) + query(row1, col1);
    }
    int query(int row, int col) {
        row++; col++;
        int sum = 0;
        for(int i = row; i > 0; i -= (i & -i)) {
            for(int j = col; j > 0; j -=(j & -j)) {
                sum += C[i][j];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
