/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    'use strict';
    var candidate = 0,cnt = 0;
    for(let num of nums){
        if(num == candidate) cnt ++;
        else if(cnt === 0){ candidate = num; cnt = 1; }
        else cnt --;
    }
    return candidate;
};
