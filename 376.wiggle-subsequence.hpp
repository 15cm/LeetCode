class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        vector<vector<int>> f(2, vector<int>(n));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                if(diff < 0) {
                    f[0][i] = max(f[0][i], f[1][j]);
                } else if(diff > 0) {
                    f[1][i] = max(f[1][i], f[0][j]);
                }
            }
            f[0][i]++;
            f[1][i]++;
        }
        return max(f[0][n-1], f[1][n-1]);
    }
};
