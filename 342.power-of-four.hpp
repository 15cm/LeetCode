class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 1) return false;
        const double eps = 1e-7;
        double tmp = log(num) / log(4);
        return tmp - floor(tmp) <= eps;
    }
};
