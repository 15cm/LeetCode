class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const auto &lhs, const auto &rhs) {
                 return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] > rhs[1];
             });
        int n = intervals.size();
        int ans = 0;
        vector<int> todo(n, 2);
        for(int i = n - 1; i >= 0; i--) {
            auto &itv = intervals[i];
            int s = itv[0], t = todo[i];
            for(int p = s; p < s + t; p++) {
                for(int j = 0; j < i; j++) {
                    if(todo[j] > 0 && p <= intervals[j][1])
                        todo[j]--;
                }
                ans++;
            }
        }
        return ans;
    }
};
