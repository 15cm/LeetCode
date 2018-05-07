class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        return max(ans, cnt);
    }
};
