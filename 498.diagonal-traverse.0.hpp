class Solution {
    vector<vector<int>> dirs {{-1, 1}, {1, -1}};
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);
        for(int i = 0, r = 0, c = 0, d = 0; i < m * n; i++) {
            ans[i] = matrix[r][c];
            r += dirs[d][0];
            c += dirs[d][1];
            if(r >= m) {
                r = m - 1;
                c += 2;
                d ^= 1;
            }
            if(c >= n) {
                c = n - 1;
                r += 2;
                d ^= 1;
            }
            if(r < 0) {
                r = 0;
                d ^= 1;
            }
            if(c < 0) {
                c = 0;
                d ^= 1;
            }
        }
        return ans;
    }
};
