class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < height.size(); i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int idx = st.top(); st.pop();
                if(st.empty()) break;
                int d = i - st.top() - 1;
                int boundedHeight = min(height[i], height[st.top()]) - height[idx];
                ans += d * boundedHeight;
            }
            st.push(i);
        }
        return ans;
    }
};
