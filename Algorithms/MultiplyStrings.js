/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */

var multiply = function(num1, num2) {
    'use strict';
    var m = num1.length, n = num2.length;
    var d = new Uint8Array(m+n);
    for(let i = m-1; i >= 0; i --){
        for(let j = n-1; j >= 0; j --){
            let val = parseInt(num1[i]) * parseInt(num2[j]);
            let p1 = i + j, p2 = p1 + 1;
            let sum = val + d[p2];
            // carry
            d[p1] += parseInt(sum/10);
            // after add
            d[p2] = sum % 10;
        }
    }
    var ans = [];
    for(let p of d){
        if(!(ans.length == 0 && p == 0)) ans.push(p);
    }
    return ans.length == 0 ? '0' : ans.join('');
};
