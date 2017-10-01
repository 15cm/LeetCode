class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int num: nums) {
            if(mp.count(num)) continue;
            int left = mp.count(num - 1) ? mp[num - 1] : 0;
            int right = mp.count(num + 1) ? mp[num + 1] : 0;
            int len = left + right + 1;
            mp[num] = len;

            ans = max(ans, len);
            mp[num - left] = len;
            mp[num + right] = len;
        }
        return ans;
    }
};
