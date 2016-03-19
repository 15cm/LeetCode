/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    'use strict';
    var n = s.length,
        r1 = numRows + numRows - 2;
    if(numRows == 1) return s;
    var ans = [];
    for(let r = 0; r < numRows; r ++){
        for(let c = r; c < n; c += r1){
            ans.push(s[c]);
            let r2 = 2 * (numRows - 1 - r);
            if(r > 0 && r < numRows - 1 && c + r2 < n){
                ans.push(s[c+r2]);
            }
        }
    }
    return ans.join('');
};

