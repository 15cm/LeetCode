class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int x: nums) {
            int cnt = ++mp[x];
            int lt = x - 1, gt = x + 1;
            if(mp.count(lt)) {
                ans = max(ans, cnt + mp[lt]);
            }
            if(mp.count(gt)) {
                ans = max(ans, cnt + mp[gt]);
            }
        }
        return ans;
    }
};
