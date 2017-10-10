class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi) {
            if(nums[lo] < nums[hi]) return nums[lo];
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] >= nums[lo]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};
