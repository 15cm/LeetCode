/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @param {Interval} newInterval
 * @return {Interval[]}
 */
var insert = function(intervals, newInterval) {
    var ans = [], n = intervals.length;
    var i = 0;
    while(i < n && intervals[i].end < newInterval.start)
        ans.push(intervals[i++]);
    while(i < n && intervals[i].start <= newInterval.end){
        newInterval = new Interval(
            Math.min(intervals[i].start, newInterval.start),
            Math.max(intervals[i].end, newInterval.end)
        );
        i++;
    }
    ans.push(newInterval);
    while(i < n) ans.push(intervals[i++]);
    return ans;
};
