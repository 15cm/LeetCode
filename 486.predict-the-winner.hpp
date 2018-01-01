class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n));
        for(int i = n-1; i >= 0; i--) {
            f[i][i] = nums[i];
            for(int j = i+1; j < n; j++) {
                f[i][j] = max(nums[i] - f[i+1][j], nums[j] - f[i][j-1]);
            }
        }
        return f[0][n-1] >= 0;
    }
};
