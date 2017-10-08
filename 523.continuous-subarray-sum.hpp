class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(k != 0) sum %= k;
            if(mp.count(sum)) {
                if(i - mp[sum] > 1) return true;
            } else {
                mp[sum] = i;
            }
        }
        return false;
    }
};
