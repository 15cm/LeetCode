class Solution {
    vector<vector<int>> memo;
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr(nums.size() + 2);
        int n = 1;
        for(int x: nums) if(x > 0) arr[n++] = x;
        arr[0] = arr[n] = 1;

        memo = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return dfs(0, n, arr);
    }
    int dfs(int left, int right, vector<int>& nums) {
        if(left + 1 == right) return 0;
        if(memo[left][right] > 0) return memo[left][right];
        int ans = 0;
        for(int i = left + 1; i < right; i++) {
            ans = max(ans, nums[i] * nums[left] * nums[right] + dfs(left, i, nums) + dfs(i, right, nums));
        }
        return memo[left][right] = ans;
    }
};
