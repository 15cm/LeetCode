class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans = 0;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++) {
            while(!stk.empty() && heights[i] <= heights[stk.top()]) {
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
