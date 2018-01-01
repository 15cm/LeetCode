class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto& lhs, auto& rhs) { return lhs[0] < rhs[0]; });
        int n = pairs.size();
        vector<int> f(n, 1);
        int ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
