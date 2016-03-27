/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    'use strict';
    if(nums === null) return null;
    if(nums.length <= 2) return [...new Set(nums)];
    var candidate1 = 0, candidate2 = 1, cnt1 = 0, cnt2 = 0;
    for(let num of nums){
        if(num == candidate1) cnt1 ++;
        else if(num == candidate2) cnt2 ++;
        else if(cnt1 === 0){
            candidate1 = num;
            cnt1 = 1;
        }
        else if(cnt2 === 0){
            candidate2 = num;
            cnt2 = 1;
        }
        else{
            cnt1 --; cnt2 --;
        }
    }
    var ans = [], checkCnt1 = 0, checkCnt2 = 0;
    for(let num of nums){
        if(candidate1 == num) checkCnt1 ++;
        if(candidate2 == num) checkCnt2 ++;
    }
    if(checkCnt1 > Math.floor(nums.length/3)) ans.push(candidate1);
    if(checkCnt2 > Math.floor(nums.length/3)) ans.push(candidate2);
    return ans;
};
