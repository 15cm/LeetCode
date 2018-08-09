/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Line {
    int x, val;
    Line(int x, int val): x(x), val(val) {}
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Line> lines;
        for(auto &itvs: schedule)
            for(auto &itv: itvs) {
                lines.emplace_back(itv.start, 1);
                lines.emplace_back(itv.end, -1);
            }
        sort(lines.begin(), lines.end(),
             [](const Line &lhs, const Line &rhs) {
                 return lhs.x < rhs.x ||
                                lhs.x == rhs.x && lhs.val > rhs.val;
             });
        vector<Interval> ans;
        int cnt = 1;
        int l;
        int n = lines.size();
        for(int i = 1; i < n - 1; i++) {
            Line &line = lines[i];
            int tmp = cnt;
            cnt += line.val;
            if(tmp == 0) {
                ans.emplace_back(l, line.x);
            } else if(cnt == 0) {
                l = line.x;
            }
        }
        return ans;
    }
};
