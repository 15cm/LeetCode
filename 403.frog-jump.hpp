class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) return false;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        vector<unordered_set<int>> f(n);
        f[1].insert(1);
        for(int i = 1; i < n; i++) {
            for(int jump: f[i]) {
                for(int k = jump-1; k <= jump+1; k++) {
                    if(k != 0 && mp.count(stones[i] + k)) {
                        int j = mp[stones[i] + k];
                        f[j].insert(k);
                    }
                }
            }
        }
        return !f[n-1].empty();
    }
};
