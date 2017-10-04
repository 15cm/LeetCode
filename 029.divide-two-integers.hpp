#define MAX_INT numeric_limits<int>::max()
#define MIN_INT numeric_limits<int>::min()
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == MIN_INT && divisor == -1))
            return MAX_INT;
        long dvd = labs(dividend);
        long dvs = labs(divisor);

        int times = 0;
        long exp, tmp;
        while(dvd >= dvs) {
            exp = 1, tmp = dvs;
            while(dvd >= (tmp << 1)) {
                tmp <<= 1;
                exp <<= 1;
            }
            dvd -= tmp;
            times += exp;
        }

        return (dividend ^ divisor) >= 0 ? times : -times;
    }
};
