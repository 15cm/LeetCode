class Solution {
public:
    // dp
    // int lengthOfLIS(vector<int>& nums) {
    //     if(nums.empty()) return 0;
    //     int n = nums.size();
    //     vector<int> f(n);
    //     int ans = 0;
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < i; j++) {
    //             if(nums[j] < nums[i])
    //                 f[i] = max(f[i], f[j]);
    //         }
    //         f[i]++;
    //         ans = max(f[i], ans);
    //     }
    //     return ans;
    // }
    // dp with binary sort
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n);
        int len = 0;
        for(int num: nums) {
            int i = lower_bound(d.begin(), d.begin() + len, num) - d.begin();
            if(i == len) {
                d[len++] = num;
            } else {
                d[i] = num;
            }
        }
        return len;
    }
};
