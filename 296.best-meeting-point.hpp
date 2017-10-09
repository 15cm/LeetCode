typedef vector<int> VI;
typedef vector<int> VI;
typedef vector<VI> VVI;

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        VI rows, cols;
        collectRows(grid, rows);
        collectCols(grid, cols);
        return computeDistance(rows) + computeDistance(cols);
    }
    void collectRows(VVI& grid, VI& rows) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j])
                    rows.push_back(i);
    }
    void collectCols(VVI& grid, VI& cols) {
        int m = grid.size(), n = grid[0].size();
        for(int j = 0; j < n; j++)
            for(int i = 0; i < m; i++)
                if(grid[i][j])
                    cols.push_back(j);
    }
    int computeDistance(VI& idxs) {
        int d = 0;
        for(int i = 0, j = idxs.size() - 1; i < j; i++, j--) {
            d += idxs[j] - idxs[i];
        }
        return d;
    }
};
