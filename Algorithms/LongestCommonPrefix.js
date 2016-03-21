/**
 *  * @param {string[]} strs
 *   * @return {string}
 *    */
var longestCommonPrefix = function(strs) {
    'use strict';
    if(strs.length === 0) return '';
    var n = Math.min(...strs.map(str=>str.length));
    for(var j = 0; j < n; j ++){
        for(let i = 1; i < strs.length; i ++)
            if(strs[i-1][j] !== strs[i][j]) return strs[0].substr(0,j);
    }
    return strs[0].substr(0,j);
};

console.log(longestCommonPrefix(['abc','aaa']));
