/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    'use strict';
    var n = nums.length, d = new Array(n);
    d[0]  = nums[0];
    for(let i = 0; i < n; i ++){
        if(d[i-1] > 0) d[i] = d[i-1] + nums[i];
        else d[i] = nums[i];
    }
    var maxSum = d[0];
    for(let i = 1; i < n; i ++)
        if(d[i] > maxSum) maxSum = d[i];
    return maxSum;
};
