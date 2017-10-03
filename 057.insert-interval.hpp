/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

typedef Interval ITV;
typedef vector<ITV> VITV;
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        VITV ans;
        auto it = intervals.begin();
        VITV& itvs = intervals;
        ITV& newItv = newInterval;
        while(it != itvs.end() && it->end < newItv.start) {
            ans.push_back(*(it++));
        }
        while(it != itvs.end() && it->start <= newItv.end) {
            newItv.start = min(it->start, newItv.start);
            newItv.end = max(it->end, newItv.end);
            it++;
        }
        ans.push_back(newItv);
        while(it != itvs.end()) {
            ans.push_back(*(it++));
        }
        return ans;
    }
};
