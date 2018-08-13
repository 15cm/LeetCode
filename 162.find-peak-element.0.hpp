class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mi = lo + (hi - lo) / 2;
            bool left = (mi == 0 || nums[mi] > nums[mi - 1]),
                right = (mi == n - 1 || nums[mi] > nums[mi + 1]);
            if(left && right) return mi;
            else if(left && !right) lo = mi + 1;
            else hi = mi - 1;
        }
        return lo;
    }
};
