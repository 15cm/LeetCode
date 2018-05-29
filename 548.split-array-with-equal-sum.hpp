
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 7) return false;
        unordered_map<int, vector<int>> mp;
        vector<int> sum(n);
        for(int i = 0; i < n; i++) {
            sum[i] = (i > 0 ? sum[i - 1] : 0) + nums[i];
            mp[sum[i]].push_back(i);
        }
        for(int i = 1; i < n - 4; i++) {
            int x = sum[i-1];
            int targetK = sum[n - 1] - x;
            if(!mp.count(targetK)) continue;
            auto& kCands = mp[targetK];
            auto kCandsBegin = upper_bound(kCands.begin(), kCands.end(), i + 3);
            int targetJ = sum[i] + x;
            if(!mp.count(targetJ)) continue;
            auto& jCands = mp[targetJ];
            auto jCandsBegin = upper_bound(jCands.begin(), jCands.end(), i);
            for(auto itK = kCandsBegin; itK != kCands.end(); itK++) {
                int k = *itK;
                for(auto itJ = jCandsBegin; itJ != jCands.end(); itJ++) {
                    int j = *itJ + 1;
                    if(j >= k - 1) break;
                    if(sum[k - 1] - sum[j] == x) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
