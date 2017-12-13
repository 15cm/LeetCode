class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> f(n), path(n, -1);
        path[0] = 0;

        int res = 0, dst = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && f[j] > f[i]) {
                    f[i] = f[j];
                    path[i] = j;
                }
            }
            f[i]++;
            if(f[i] > res) {
                res = f[i];
                dst = i;
            }
        }

        vector<int> ans(res);
        for(int i = res - 1; i >= 0; i--) {
            ans[i] = dst;
            dst = path[dst];
        }
        return ans;
    }
};
