/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<pair<int, int>> lefts;
        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            lefts.push_back({intervals[i].start, i});
        }
        sort(lefts.begin(), lefts.end());
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(lefts.begin(), lefts.end(), intervals[i].end, [](auto& lhs, auto& rhs) {
                    return lhs.first < rhs;
                });
            if(it != lefts.end())
                ans[i] = it->second;
        }
        return ans;
    }
};
