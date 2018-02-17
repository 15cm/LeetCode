class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxn = pow(3, floor(log(INT_MAX)/log(3)));
        return n > 0 && maxn % n == 0;
    }
};
