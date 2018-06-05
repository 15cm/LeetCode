class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0, prevCnt = 1; i < n; i++) {
            int cnt = 1;
            bool ok = (i > 0 && nums[i] == nums[i-1] + 1);
            while(i < n - 1 && nums[i] == nums[i+1]) {
                cnt++;
                i++;
            }
            if(ok) {
                ans = max(ans, prevCnt + cnt);
            }
            prevCnt = cnt;
        }
        return ans;
    }
};
