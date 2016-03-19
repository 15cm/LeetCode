/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    var y = 0,t = x;
    if(x < 0) return false;
    while(t !== 0){
        y = y * 10 + t % 10;
        t = parseInt(t/10);
    }
    if(x - y === 0) return true;
    else return false;
};

