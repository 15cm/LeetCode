/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    'use strict'
    var ans = [],carry = 0;
    if(a.length < b.length){
        let t = a;
        a = b;
        b = t;
    }
    var m = a.length, n = b.length;
    for(let i = m-1,j = n-1; i >= 0; i --, j--){
        let x = parseInt(a[i]) + carry;
        if(j >= 0) x += parseInt(b[j]);
        ans.unshift(x & 1);
        carry = parseInt(x>>1);
    }
    if(carry > 0) ans.unshift(carry);
    return ans.join('');
};
