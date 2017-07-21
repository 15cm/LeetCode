#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> rowHeights(n, vector<int>(m));
        for(int c = 0; c < m; c++) rowHeights[0][c] = matrix[0][c] - '0';
        for(int r = 1; r < n; r++)
            for(int c = 0; c < m; c++)
                rowHeights[r][c] = matrix[r][c] == '0' ? 0 : rowHeights[r-1][c] + 1;
        int ans = 0;
        for(int r = 0; r < n; r++) {
            ans = max(ans, maxHist(rowHeights[r]));
        }
        return ans;
    }
    int maxHist(vector<int>& heights) {
        int ans = 0;
        stack<int> s;
        for(int i = 0; i <= heights.size(); i ++) {
            int curHeight = i == heights.size() ? -1 : heights[i];
            while(!s.empty() && heights[s.top()] >= curHeight) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                ans = max(ans, h * w);
            }
            s.push(i);
        }
        return ans;
    }
};
