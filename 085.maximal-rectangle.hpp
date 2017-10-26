class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n;j++) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            ans = max(ans, maxArea(heights));
        }
        return ans;
    }
    int maxArea(vector<int>& heights) {
        int ans = 0;
        stack<int> stk;
        for(int i = 0; i <= heights.size(); i++) {
            int curHeight = i == heights.size() ? -1 : heights[i];
            while(!stk.empty() && curHeight <= heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - 1 - stk.top();
                ans = max(ans, h * w);
            }
            stk.push(i);
        }
        return ans;
    }
};
