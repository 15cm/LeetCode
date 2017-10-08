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
    //Discretization
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        int n = intervals.size();
        pair<int, int> rs[n*2];
        for(int i = 0; i < n; i++) {
            rs[i*2] = make_pair(intervals[i].start, 1);
            rs[i*2 + 1] = make_pair(intervals[i].end, -1);
        }
        sort(rs, rs + n*2);
        int cnt = 0, ans = 0;
        for(int i = 0; i < n*2; i++) {
            cnt += rs[i].second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
