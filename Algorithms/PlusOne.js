/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    'use strict'
    var carry = 0, n = digits.length-1, ans = [];
    for(let i = n; i >=0; i--){
        let x = digits[i] + carry;
        if(i == n) x += 1;
        ans.unshift(x%10);
        carry = parseInt(x/10);
    }
    if(carry>0) ans.unshift(carry);
    return ans;
};
