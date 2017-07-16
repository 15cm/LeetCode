#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++) {
                if(!(i == 0 && j == 0)) {
                    if(i == 0) grid[i][j] += grid[i][j-1];
                    else if(j == 0) grid[i][j] += grid[i-1][j];
                    else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
            }
        return grid.back().back();
    }
};
