class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int prevCnt = 0, cnt = 0, gap = 0;
        int ans = 0;
        int i = 0;
        while(i < n) {
            while(i < n && nums[i] == 1) {
                i++;
                cnt++;
            }
            ans = max(ans, cnt + min(1, gap) + (gap == 1 ? prevCnt : 0));
            prevCnt = cnt;
            cnt = 0;
            gap = 0;
            while(i < n && nums[i] == 0) {
                i++;
                gap++;
            }
        }
        ans = max(ans, cnt + min(1, gap) + (gap == 1 ? prevCnt : 0));
        return ans;
    }
};
