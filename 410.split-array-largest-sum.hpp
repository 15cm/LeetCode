class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> S(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            S[i][i] = nums[i];
            for(int j = i+1; j < n; j++)
                S[i][j]= S[i][j-1] + nums[j];
        }
        vector<int> f(n);
        // s = 0;
        for(int i = 0; i < n; i++)
            f[i] = S[0][i];

        for(int s = 1; s < m; s++) {
            for(int i = n-1; i >= s-1; i--) {
                f[i] = INT_MAX;
                for(int j = max(s-2, 0); j < i; j++) {
                    f[i] = min(f[i], max(f[j], S[j+1][i]));
                }
            }
        }
        return f[n-1];
    }
};
