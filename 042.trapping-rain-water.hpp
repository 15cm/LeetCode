class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int n = height.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int h = height[i];
            while(!stk.empty() && h > height[stk.top()]) {
                int j = stk.top(); stk.pop();
                if(stk.empty()) break;
                int k = stk.top();
                int d = i - k - 1;
                ans += d * (min(h, height[k]) - height[j]);
            }
            stk.push(i);
        }
        return ans;
    }
};
