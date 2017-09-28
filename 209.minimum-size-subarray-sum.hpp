class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int lo = 0, hi = 0, sum = 0, n = nums.size();
        vector<int> f(n, numeric_limits<int>::max());
        while(hi < n) {
            sum += nums[hi];
            if(sum >= s) {
                while(lo < hi && sum - nums[lo] >= s) {
                    sum -= nums[lo];
                    lo++;
                }
                f[hi] = hi - lo + 1;
            }
            hi++;
        }
        if(sum < s) return 0;
        int ans = f[0];
        for(int d: f) ans = min(ans, d);
        return ans;
    }
};
