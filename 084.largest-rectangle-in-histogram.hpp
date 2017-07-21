#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        stack<int> s;
        int ans = 0;
        for(int i = 0; i <= heights.size(); i++) {
            int curHeight = i == heights.size() ? -1 : heights[i];
            while(!s.empty() && heights[s.top()] >= curHeight) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - 1 - s.top();
                ans = max(ans, h * w);
            }
            s.push(i);
        }
        return ans;
    }
};
