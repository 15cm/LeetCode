class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> f(n ,vector<int>(n));

        int sRow = 0, eRow = n - 1;
        int sCol = 0, eCol = n - 1;
        int p = 1;

        while(sRow <= eRow && sCol <= eCol) {
            for(int i = sCol; i <= eCol; i++)
                f[sRow][i] = p++;
            sRow++;

            for(int i = sRow; i <= eRow; i++)
                f[i][eCol] = p++;
            eCol--;
            if(sCol > eCol) break;

            for(int i = eCol; i >= sCol; i--)
                f[eRow][i] = p++;
            eRow--;
            if(sRow > eRow) break;

            for(int i = eRow; i >= sRow; i--)
                f[i][sCol] = p++;
            sCol++;
        }
        return f;
    }
};
