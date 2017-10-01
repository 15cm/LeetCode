/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

typedef Interval I;
typedef vector<I> VI;

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        VI ans;
        if(intervals.empty()) return ans;
        sort(intervals.begin(), intervals.end(), [](const I& lhs, const I& rhs) {
                return lhs.start < rhs.start;
            });
        int s = intervals[0].start, e = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++) {
            I& itv = intervals[i];
            if(itv.start <= e) {
                e = max(e, itv.end);
            } else {
                ans.push_back(I(s, e));
                s = itv.start;
                e = itv.end;
            }
        }
        ans.push_back(I(s, e));
        return ans;
    }
};
