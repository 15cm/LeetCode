/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    'use strict';
    var findMid = (a1,a2)=>{
        if(a1.length > a2.length){
            let t = a1;
            a1 = a2;
            a2 = t;
        }
        var n1 = a1.length, n2 = a2.length, m1 = parseInt((n1-1)/2), m2 = parseInt((n2-1)/2);
        if(n1 <= 2){
            let a = a1.concat(a2).sort((x,y)=>x - y);
            let n = a.length, m = parseInt((n-1)/2);
            if(n % 2 == 0) return (a[m] + a[m+1])/2;
            else return a[m];
        }
        if(a1[m1] <= a2[m2]){
            return findMid(a1.slice(m1,n1),a2.slice(0,n2-m1));
        }
        else{
            return findMid(a1.slice(0,n1-m1),a2.slice(m1,n2));
        }
    }
    return findMid(nums1,nums2);
};

