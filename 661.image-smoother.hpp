class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<int> sum(n);
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j < n; j++) {
                if(i < m) sum[j] += M[i][j];
                if(i >= 3) sum[j] -= M[i-3][j];
            }
            if(i == 0) continue;
            for(int j = 0; j < n; j++) {
                int tmp = sum[j], sz = ((i == 1 || i == m) ? min(m, 2) : 3), cnt = sz;
                if(j > 0) {
                    tmp += sum[j-1];
                    cnt += sz;
                }
                if(j < n - 1) {
                    tmp += sum[j+1];
                    cnt += sz;
                }
                ans[i-1][j] = tmp / cnt;
            }
        }
        return ans;
    }
};
