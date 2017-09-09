class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty() || dungeon[0].empty()) return 0;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, numeric_limits<int>::max()));
        f[m][n-1] = f[m-1][n] = 1;
        for(int i = m - 1; i >= 0; i--)
            for(int j = n - 1; j >= 0; j--) {
                int need = min(f[i+1][j], f[i][j+1]) - dungeon[i][j];
                f[i][j] = need <= 0 ? 1 : need;
            }
        return f[0][0];
    }
};
