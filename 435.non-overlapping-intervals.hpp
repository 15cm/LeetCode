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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& lhs, auto& rhs) {
                return lhs.start < rhs.start || lhs.start == rhs.start && lhs.end < rhs.end;
            });
        int cnt = 0;
        int n = intervals.size();
        for(int i = 0, j = 1; j < n; j++) {
            auto& a = intervals[i], &b = intervals[j];
            if(a.start == b.start) {
                cnt++;
            } else if(a.end <= b.start) {
                i = j;
            } else {
                if(a.end > b.end) {
                    i = j;
                }
                cnt++;
            }
        }
        return cnt;
    }
};
