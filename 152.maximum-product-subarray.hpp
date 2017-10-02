class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = nums[0], iMax = ans, iMin = ans;
        for(int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if(num < 0) {
                swap(iMax, iMin);
            }
            iMax = max(num, iMax * num);
            iMin = min(num, iMin * num);
            ans = max(ans, iMax);
        }
        return ans;
    }
};
