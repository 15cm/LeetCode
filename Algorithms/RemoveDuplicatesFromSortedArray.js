/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    'use strict';
    var n = nums.length, p = 1;
    if(n < 2) return n;
    for(let i = 1; i < n; i ++)
        if(nums[i] != nums[i-1]) nums[p++] = nums[i];
    return p;
};
