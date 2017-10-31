class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 2) return 0;
        int ans = 0;
        for(int i = 0, j = 1; j < n; j++) {
            if(height[j] > height[i]) {
                ans += compute(i, j, height);
                i = j;
            }
        }
        for(int i = n - 1, j = n - 2; j >= 0; j--) {
            if(height[j] >= height[i]) {
                ans += compute(i, j, height);
                i = j;
            }
        }
        return ans;
    }
    int compute(int i, int j, vector<int>& height) {
        if(j < i) swap(i, j);
        int area = (j - i - 1) * min(height[i], height[j]);
        for(int k = i + 1; k < j; k++) {
            area -= height[k];
        }
        return area;
    }
};
