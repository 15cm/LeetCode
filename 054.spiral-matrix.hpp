class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return vector<int>();
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);
        int p = 0;

        int sRow = 0, eRow = m - 1;
        int sCol = 0, eCol = n - 1;
        while(sRow <= eRow && sCol <= eCol) {
            for(int i = sCol; i <= eCol; i++)
                ans[p++] = matrix[sRow][i];
            sRow++;

            for(int i = sRow; i <= eRow; i++)
                ans[p++] = matrix[i][eCol];
            eCol--;

            if(sRow > eRow) break;
            for(int i = eCol; i >= sCol; i--)
                ans[p++] = matrix[eRow][i];
            eRow--;

            if(sCol > eCol) break;
            for(int i = eRow; i >= sRow; i--)
                ans[p++] = matrix[i][sCol];
            sCol++;
        }
        return ans;
    }
};
