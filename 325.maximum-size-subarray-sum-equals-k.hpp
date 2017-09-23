class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(!mp.count(sum))
                mp[sum] = i;
            if(mp.count(sum - k))
                len = max(len, i - mp[sum - k]);
        }
        return len;
    }
};
