class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        for(int &num: nums) num++;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) continue;
            ans = max(ans, dfs(i, nums));
        }
        return ans;
    }
    int dfs(int p, vector<int> &nums) {
        if(nums[p] < 0) return 0;
        int next = nums[p] - 1;
        nums[p] = -nums[p];
        return 1 + dfs(next, nums);
    }
};
