#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty()) return ans;
        int m = matrix.size(), n = matrix[0].size();
        int r1 = 0, c1 = 0, r2 = m -1, c2 = n - 1;
        for(; r1 < r2 && c1 < c2; r1++, c1++, r2--, c2--)
            visitMargin(r1, c1, r2, c2, matrix, ans);
        if(r1 == r2) for(int c = c1; c <= c2; c ++) ans.push_back(matrix[r1][c]);
        else if(c1 == c2) for(int r = r1; r <= r2; r ++) ans.push_back(matrix[r][c1]);
        return ans;
    }
    void visitMargin(int r1, int c1, int r2, int c2, vector<vector<int>>& m, vector<int>& ans) {
        for(int c = c1; c <= c2; c ++) ans.push_back(m[r1][c]);
        for(int r = r1 + 1; r <= r2; r ++) ans.push_back(m[r][c2]);
        for(int c = c2 - 1; c >= c1; c --) ans.push_back(m[r2][c]);
        for(int r = r2 - 1; r >= r1 + 1; r --) ans.push_back(m[r][c1]);
    }
};
