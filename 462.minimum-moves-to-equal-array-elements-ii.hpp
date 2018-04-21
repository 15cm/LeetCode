class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        sort(nums.begin(), nums.end());
        int v = nums[n/2];
        int ans = 0;
        for(int x: nums)
            ans += abs(x-v);
        return ans;
    }
};
