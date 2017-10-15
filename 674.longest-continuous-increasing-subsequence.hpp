class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i = 0, j = 1, n = nums.size();
        int ans = 1;
        while(j < n) {
            if(nums[j] > nums[j-1]) {
                j++;
                ans = max(ans, j - i);
            } else {
                i = j; j = i + 1;
            }
        }
        return ans;
    }
};
