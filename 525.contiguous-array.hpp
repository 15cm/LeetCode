class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(2 * n + 1, -1);
        int ans = 0;
        for(int i = 0, cnt = 0; i < n; i++) {
            cnt += (nums[i] ? 1 : -1);
            int idx = cnt + n;
            if(cnt == 0 || mp[idx] != -1) {
                ans = max(ans, i - mp[idx]);
            } else {
                mp[idx] = i;
            }
        }
        return ans;
    }
};
