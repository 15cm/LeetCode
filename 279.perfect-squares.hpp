class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for(int i = 1; i*i <= n; i++)
            nums.push_back(i*i);
        int ans = INT_MAX;
        dfs(nums.size() - 1, n, 0, ans, nums);
        return ans;
    }
    void dfs(int p, int rem, int cnt, int& ans, vector<int>& nums) {
        if(rem == 0) {
            ans = min(cnt, ans);
        }
        if(rem <= 0) {
            return;
        }
        if(cnt >= ans) return;
        int n = nums.size();
        for(int i = p; i >= 0; i--) {
            dfs(i, rem - nums[i], cnt + 1, ans, nums);
        }
    }
};
