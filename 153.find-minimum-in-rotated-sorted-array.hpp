class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        int s = 0, e = nums.size() - 1;
        while(s < e) {
            if(nums[s] < nums[e]) return nums[s];
            int m = (s + e) / 2;
            if(nums[m] >= nums[s]) s = m + 1;
            else e = m;
        }
        return nums[s];
    }
};
