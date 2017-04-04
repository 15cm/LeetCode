class Solution {
public:
    const int MAX_INT = 0x7fffffff;
    const int MIN_INT = 0x80000000;
    int revabs(int a) {return a > 0 ? -a : a;}
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 0) return MAX_INT;
        if(dividend == MIN_INT) {
            if(divisor == 1) return MIN_INT;
            else if(divisor == -1) return MAX_INT;
        }
        if(divisor == MIN_INT) {
            if(dividend == MIN_INT) return 1;
            else return 0;
        }
        bool sign;
        int ans = 0;
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) sign = true;
        else sign = false;
        dividend = revabs(dividend);
        divisor = revabs(divisor);
        search(dividend, divisor, 1, divisor, ans);
        return sign ? ans : -ans;
    }
    void search(int dividend, int divisor, int quotient, int step, int& ans) {
        if(dividend > step) return;
        int tmp = dividend - divisor;
        if(tmp < 0) {
            ans += quotient;
            search(tmp, divisor + divisor, quotient + quotient, step, ans);
        }
        else if(tmp == 0) {
            ans += quotient;
            return;
        }
        else search(dividend, step, 1, step, ans);
    }
};
