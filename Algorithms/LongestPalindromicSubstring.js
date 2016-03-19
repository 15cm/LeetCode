/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    'use strict';
    var arr = Array.from(s);
    arr.unshift('$'); arr.push('^');
    var str = arr.join('#');
    var n = str.length, p = new Array(n), id = 0, mx = 0;
    p.fill(0);
    for(let i = 1; i < n - 1; i ++){
        p[i] = mx > i ? Math.min(p[2*id-i],mx-i) : 1;
        while(str[i+p[i]] == str[i-p[i]]) p[i]++;
        if(i + p[i] > mx){
            mx = i + p[i];
            id = i;
        }
    }
    var maxLen = 0, index = 0;
    for(let i = 1; i < n - 1; i ++){
        if(p[i] > maxLen){
            maxLen = p[i];
            index = i;
        }
    }
    return s.substr((index-maxLen)/2,maxLen-1);
};

