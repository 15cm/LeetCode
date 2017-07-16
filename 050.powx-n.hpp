#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        double ans = 1;
        if(n < 0) {
            x = 1/x;
            if(n == (1 << 31)) {
                n += 1;
                ans *= x;
            }
            n = -n;
        }
        double pows[34];
        int p = 0;
        double tmp = x;
        for(int _n = n; _n > 0; _n >>= 1, p ++){
            pows[p] = tmp;
            tmp *= tmp;
        }
        int i = p - 1, m = n;
        while(m > 0) {
            int thePow = 1 << i;
            if(m >= thePow) {
                m -= thePow;
                ans *= pows[i];
            } else {
                i -= 1;
            }
        }
        return ans;
    }
};
