class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxp, minp, ans;
        maxp = minp = ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int e = nums[i];
            if(e >= 0) {
                maxp = max(maxp * e, e);
                minp = min(minp * e, e);
            } else {
                int tmp = maxp;
                maxp = max(minp * e, e);
                minp = min(tmp * e, e);
            }
            ans = max(ans, maxp);
        }
        return ans;
    }
};
