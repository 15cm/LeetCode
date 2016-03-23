/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    'use strict';
    var swap = (i,j)=>{
        let t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    var partition = (lo,hi)=>{
        if(lo >= hi) return hi;
        var i = lo, j = hi + 1, v = nums[lo];
        while(true){
            while(nums[++i] < v)if(i == hi) break;
            while(nums[--j] > v);
            if(i >= j) break;
            swap(i,j);
        }
        swap(lo,j);
        return j;
    }
    var find = (lo,hi)=>{
        if(lo >= hi) return nums[hi];
        var mid = partition(lo,hi);
        var len = hi - mid;
        if(k <= len){
            return find(mid+1,hi);
        }else if(k == len + 1){
            return nums[mid];
        }else{
            k -= len + 1;
            return find(lo,mid-1);
        }
    }
    return find(0,nums.length-1);
};

