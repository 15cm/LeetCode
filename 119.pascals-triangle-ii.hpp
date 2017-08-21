class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> f(2, vector<int>(rowIndex + 1));
        f[0][0] = 1;
        for(int i = 1; i <= rowIndex; i++) {
            f[1][0] = f[1][i] = 1;
            for(int j = 1; j < i; j++)
                f[1][j] = f[0][j] + f[0][j-1];
            f[0] = f[1];
        }
        return f[0];
    }
};
