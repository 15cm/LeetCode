class Solution {
public:
    int trap(vector<int>& height) {
        int maxl = 0, maxr = 0;
        int n = height.size();
        int ans = 0;
        for(int l = 0, r = n-1; l < r; ) {
            int hl = height[l], hr = height[r];
            if(hl < hr) {
                ans += max(0, maxl - hl);
                maxl = max(maxl, hl);
                l++;
            } else {
                ans += max(0, maxr - hr);
                maxr = max(maxr, hr);
                r--;
            }
        }
        return ans;
    }
};
