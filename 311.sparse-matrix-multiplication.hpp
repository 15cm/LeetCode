class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), nB = B[0].size();
        vector<vector<int>> C(m, vector<int>(nB));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(A[i][j])
                    for(int k = 0; k < nB; k++)
                        if(B[j][k]) C[i][k] += A[i][j] * B[j][k];
        return C;
    }
};
