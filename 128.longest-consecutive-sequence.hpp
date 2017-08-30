class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto n: nums) {
            if(mp.find(n) == mp.end()) {
                int left = mp.find(n - 1) != mp.end() ? mp[n - 1] : 0;
                int right = mp.find(n + 1) != mp.end() ? mp[n + 1] : 0;
                int len = left + right + 1;
                mp[n] = len;
                mp[n - left] = mp[n + right] = len;
                ans = max(len, ans);
            }
        }
        return ans;
    }
};
