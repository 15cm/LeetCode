class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = nums[0], f = 0;
        for(int num: nums) {
            f = max(f, 0) + num;
            ans = max(ans, f);
        }
        return ans;
    }
};
