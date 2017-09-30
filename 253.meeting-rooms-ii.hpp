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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        auto cmp1 = [](const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        };
        auto cmp2 = [](const Interval& lhs, const Interval& rhs) {
            return lhs.end > rhs.end;
        };

        sort(intervals.begin(), intervals.end(), cmp1);
        priority_queue<Interval, vector<Interval>, decltype(cmp2)> pq(cmp2);
        pq.push(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            auto prev = pq.top(); pq.pop();
            auto& cur = intervals[i];
            if(prev.end > cur.start) {
                pq.push(cur);
            } else {
                prev.end = cur.end;
            }
            pq.push(prev);
        }
        return pq.size();
    }
};
