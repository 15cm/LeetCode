/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    'use strict';
    nums.sort((a,b)=>{
        return parseInt(a) - parseInt(b);
    });
    var ans,dis = Number.MAX_VALUE;
    var n = nums.length;
    var next = (i,step)=>{
        var j = i + step;
        while(j >= 0 && j <= n-1 && nums[i] == nums[j]) {
            i += step;
            j += step;
        }
        return i+step;
    };
    for(let i = 0; i < n;){
        let lo = i+1, hi = n-1;
        while(lo < hi){
            let a = nums[i], b = nums[lo], c = nums[hi];
            let sum = a+b+c;
            let t_dis = sum - target;
            if(t_dis == 0) {
                return sum;
            }
            else{
                if(Math.abs(t_dis) < dis){
                    dis = Math.abs(t_dis);
                    ans = sum;
                }
                if(t_dis < 0) lo = next(lo,1);
                if(t_dis > 0) hi = next(hi,-1);
            }
        }
        i = next(i,1);
    }
    return ans;
};

