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
typedef VITV::iterator VITVit;

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        auto& itvs = intervals;
        if(itvs.empty()) return VITV();
        VITVit i = itvs.begin(), j = itvs.begin();
        sort(itvs.begin(), itvs.end(), [](const ITV& lhs, const ITV& rhs) { return lhs.start < rhs.start; });
        while(j != itvs.end()) {
            if(j->start <= i->end) {
                i->end = max(i->end, j->end);
            } else {
                i++;
                i->start = j->start;
                i->end = j->end;
            }
            j++;
        }
        i++;
        return VITV(itvs.begin(), i);
    }
};
