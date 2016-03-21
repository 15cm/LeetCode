/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    'use strict';
    nums.sort((a,b)=>{
        return parseInt(a) - parseInt(b);
    });
    var ans = [];
    var n = nums.length;
    var next = (i,step)=>{
        var j = i + step;
        while(j >= 0 && j <= n-1 && nums[i] === nums[j]) {
            i += step;
            j += step;
        }
        return i+step;
    }
    for(let i = 0; i < n;){
        let lo = i+1, hi = n-1;
        while(lo < hi){
            let a = nums[i], b = nums[lo], c = nums[hi];
            let sum = a+b+c;
            if(sum === 0) {
                ans.push([a,b,c]);
                lo = next(lo,1);
                hi = next(hi,-1);
            }
            else if(sum < 0) lo = next(lo,1);
            else hi = next(hi,-1);
        }
        i = next(i,1);
    }
    return ans;
};

