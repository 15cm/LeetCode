/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    'use strict';
    var n = nums.length, p = 0;
    for(let i = 0; i < n; i ++)
        if(nums[i] != val) nums[p++] = nums[i];
    return p;
};
