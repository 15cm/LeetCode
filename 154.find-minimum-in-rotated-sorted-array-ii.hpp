class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        int ans = nums[0];
        dfs(0, nums.size() - 1, nums, ans);
        return ans;
    }
    bool dfs(int l, int r, vector<int>& nums, int& ans) {
        if(l >= r) {
            ans = min(nums[l], ans);
            return false;
        }
        if(nums[l] < nums[r]) {
            ans = nums[l];
            return true;
        }
        int m = (l + r) / 2;
        if(nums[m] > nums[l]) {
            return dfs(m + 1, r, nums, ans);
        } else if(nums[m] == nums[l]) {
            return dfs(m + 1, r, nums, ans) || dfs(l, m, nums, ans);
        } else {
            return dfs(l, m, nums, ans);
        }
    }
};
