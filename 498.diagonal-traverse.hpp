class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty() || matrix[0].empty()) return ans;
        int m = matrix.size(), n = matrix[0].size();
        ans = vector<int>(m * n);
        for(int i = 0, r = 0, c = 0; i < ans.size(); i++) {
            ans[i] = matrix[r][c];
            if((r + c) % 2 == 0) {
                if(c == n - 1) {
                    r++;
                } else if(r == 0) {
                    c++;
                } else {
                    r--;
                    c++;
                }
            } else {
                if(r == m - 1) {
                    c++;
                } else if(c == 0) {
                    r++;
                } else {
                    r++;
                    c--;
                }
            }
        }
        return ans;
    }
};
