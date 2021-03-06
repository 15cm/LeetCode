using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        VVI f(m + 1, VI(n + 1));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(matrix[i-1][j-1] == '1') {
                    f[i][j] = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]) + 1;
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans * ans;
    }
};
