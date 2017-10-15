class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<int> f(n, 1);
        vector<int> d(n, 1);
        int maxl = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(f[j] + 1 > f[i]) {
                        f[i] = f[j] + 1;
                        d[i] = d[j];
                        maxl = max(maxl, f[i]);
                    } else if(f[j] + 1 == f[i]) {
                        d[i] += d[j];
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(f[i] == maxl) {
                cnt += d[i];
            }
        }
        return cnt;
    }
};
