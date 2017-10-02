class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int f0 = 0, f1 = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int t = f0;
            f0 = max(f0, f1);
            f1 = t + nums[i];
        }
        return max(f0, f1);
    }
};
