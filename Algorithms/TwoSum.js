/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    'use strict'
    var numMap = new Map();
    for(let i = 0; i < nums.length; i ++){
        let x = nums[i];
        let y = target - x;
        if(y in numMap){
            return [parseInt(numMap[y]),i];
        }
        numMap[x]=i;
    }
};
