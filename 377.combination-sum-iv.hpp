class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> mp(target + 1, -1);
        return helper(nums, target, mp);
    }
    int helper(vector<int>& nums, int rem, vector<int>& mp) {
        if(rem < 0) return 0;
        if(rem == 0) return 1;
        if(mp[rem] == -1){
            mp[rem] = 0;
            for(int num: nums) {
                mp[rem] += helper(nums, rem - num, mp);
            }
        }
        return mp[rem];
    }
};
