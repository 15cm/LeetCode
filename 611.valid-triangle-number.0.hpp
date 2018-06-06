class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
                ans += it - (nums.begin() + j) - 1;
            }
        }
        return ans;
    }
};
