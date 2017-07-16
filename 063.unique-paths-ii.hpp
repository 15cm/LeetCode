#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int f[m][n];
        f[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n;j ++) {
                if(!(i == 0 && j == 0)) {
                    int fromUp = i > 0 ? f[i-1][j] : 0;
                    int fromLeft = j > 0 ? f[i][j-1] : 0;
                    f[i][j] = obstacleGrid[i][j] ? 0 : fromUp + fromLeft;
                }
            }
        }
        return f[m-1][n-1];
    }
};
