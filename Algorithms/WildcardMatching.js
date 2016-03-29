/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    'use strict';
    var sid = 0, pid = 0, starId = -1, matchId = 0, n = s.length, m = p.length;
    while(sid < n){
        if(pid < m && p[pid] == '*'){
            starId = pid ++;
            matchId = sid;
        }
        else if(pid < m && (s[sid] == p[pid] || p[pid] == '?')){
            sid ++;
            pid ++;
        }
        else if(starId >= 0){
            pid = starId + 1;
            sid = ++ matchId;
        }
        else{
            return false;
        }
    }
    while(pid < m && p[pid] == '*') pid++;
    return pid == m;
};
