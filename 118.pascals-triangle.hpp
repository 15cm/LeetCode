class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> f;
        for(int i = 0; i < numRows; i++) {
            f.push_back(vector<int>(i+1));
            f[i][0] = f[i][i] = 1;
        }
        for(int i = 1; i < numRows; i++) {
            for(int j = 1; j < i; j++)
                f[i][j] = f[i-1][j] + f[i-1][j-1];
        }
        return f;
    }
};
