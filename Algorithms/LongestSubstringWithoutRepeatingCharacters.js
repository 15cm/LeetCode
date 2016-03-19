/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    'use strict';
    var l = 0, r = 0, maxLen = 0, d = new Int32Array(128);
    d.fill(-1);
    for(;r < s.length; r++){
        let code = s.charCodeAt(r);
        if(d[code] >= 0){
            maxLen = Math.max(r-l,maxLen);
            l = Math.max(d[code]+1,l);
        }
        d[code] = r;
    }
    return Math.max(maxLen,r-l);
};

