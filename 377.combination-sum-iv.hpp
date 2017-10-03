class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> f(target + 1);
        f[0] = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= target; i++) {
            for(int j = 0; j < n && nums[j] <= i; j++) {
                f[i] += f[i - nums[j]];
            }
        }
        return f[target];
    }
};
