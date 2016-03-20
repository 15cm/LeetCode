/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @return {Interval[]}
 */
var merge = function(intervals) {
    'use strict';
    var insert = (intervals, newInterval)=>{
        var ans = [], n = intervals.length, i = 0;
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
    var ans = [];
    for(let interval of intervals)
        ans = insert(ans,interval);
    return ans;
};
