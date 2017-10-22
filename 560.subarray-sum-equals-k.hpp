class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;
        for(int i = 1; i <= nums.size(); i++) {
            sum += nums[i - 1];
            if(mp.count(sum - k)) ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};
