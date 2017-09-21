class Solution {
public:
    // DP with extra space
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> f(n), g(n), ans(n);
    //     f[0] = nums[0], g[n-1] = nums[n-1];
    //     for(int i = 1; i < n; i++) {
    //         f[i] = f[i-1] * nums[i];
    //         g[n-1-i] = g[n-i] * nums[n-i-1];
    //     }
    //     for(int i = 0; i < n; i++) {
    //         int left = i > 0 ? f[i-1] : 1;
    //         int right = i < n - 1 ? g[i+1] : 1;
    //         ans[i] = left * right;
    //     }
    //     return ans;
    // }
    // DP with constant Space
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for(int i = 1; i < n; i++)
            ans[i] = ans[i-1] * nums[i-1];
        int right = 1;
        for(int i = n-1; i >= 0; i--) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};
