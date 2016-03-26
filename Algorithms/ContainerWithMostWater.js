/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    'use strict';
     var computeV = (x1,x2,h)=>{
         return (x2-x1) * h;
     }
     var l = 0, r = height.length-1, maxV = computeV(l,r,Math.min(height[l],height[r]));
     for(let i = l, j = r; i < j;){
         if(height[i] < height[j]){
             while(height[++i] <= height[l])if(i >= j) break;
         }else{
             while(height[--j] <= height[r])if(i >= j) break;
         }
         if(computeV(i,j,Math.min(height[i],height[j])) > maxV){
             l = i; r = j;
             maxV = computeV(i,j,Math.min(height[i],height[j]));
         }
     }
     return maxV;
};
