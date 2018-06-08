class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int minv = arrays[0][0], maxv = arrays[0].back();
        int res = 0;
        for(int i = 1; i < n; i++) {
            int curMin = arrays[i][0], curMax = arrays[i].back();
            res = max(res, max(curMax - minv, maxv - curMin));
            minv = min(minv, curMin);
            maxv = max(maxv, curMax);
        }
        return res;
    }
};
