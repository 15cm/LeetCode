#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n >= 0) return myPow(x, n, 1);
        else if(n == 0x80000000) return 1 / (x * myPow(x, -(n+1), 1));
        else return 1 / myPow(x, -n, 1);
    }
    double myPow(double x, int n , double acc) {
        if(n == 0) return acc;
        if(n & 1)
            return myPow(x, n - 1, acc * x);
        else
            return myPow(x * x, n / 2, acc);
    }
};
