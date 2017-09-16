class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        else if(n == 1) return nums[0];
        return max(robRow(nums, 0, n - 2), robRow(nums, 1, n - 1));
    }
    int robRow(vector<int>& nums, int lo, int hi) {
        int include = 0, exclude = 0;
        for(int i = lo; i <= hi; i++) {
            int tmp = exclude;
            exclude = max(exclude, include);
            include = nums[i] + tmp;
        }
        return max(include, exclude);
    }
};
