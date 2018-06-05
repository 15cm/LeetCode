class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x: nums) mp[x]++;
        int ans = 0;
        for(auto &pr: mp) {
            int next = pr.first + 1;
            if(mp.count(next)) {
                ans = max(ans, pr.second + mp[next]);
            }
        }
        return ans;
    }
};
