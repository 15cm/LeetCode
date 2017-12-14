class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int down = 1, up = 1;
        for(int i = 1; i < n; i++) {
            int diff = nums[i] - nums[i-1];
            if(diff < 0) {
                down = up + 1;
            } else if(diff > 0) {
                up = down + 1;
            }
        }
        return max(up, down);
    }
};
