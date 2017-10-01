class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        for(int i = 0; i < n; i++) {
            if(i > 0) f[i] = f[i-1] * nums[i-1];
        }
        int acc = 1;
        for(int i = n - 1; i >= 0; i--) {
            f[i] *= acc;
            acc *= nums[i];
        }
        return f;
    }
};
