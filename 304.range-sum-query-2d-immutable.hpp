class NumMatrix {
public:
    vector<vector<int>> f;
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        f = decltype(f)(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + matrix[i-1][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(f.empty()) return 0;
        int r1 = row1+1, c1 = col1+1, r2 = row2+1, c2 = col2+1;
        return f[r2][c2] - f[r1-1][c2] - f[r2][c1-1] + f[r1-1][c1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
