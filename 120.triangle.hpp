class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> f(2, vector<int>(triangle.size(), 0));
        f[0][0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++) {
            f[1][0] = triangle[i][0] + f[0][0];
            f[1][i] = triangle[i][i] + f[0][i-1];
            for(int j = 1; j < i; j++)
                f[1][j] = triangle[i][j] + min(f[0][j-1], f[0][j]);
            f[0] = f[1];
        }
        int m = f[0][0];
        for(int i = 0; i < triangle.size(); i++) m = min(m, f[0][i]);
        return m;
    }
};
