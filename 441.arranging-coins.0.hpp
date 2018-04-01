class Solution {
public:
    int arrangeCoins(int n) {
        long x = (sqrt((long)n * 8 + 1) - 1) / 2;
        if((x * x + x)/2 <= n) {
            return x;
        } else {
            return x-1;
        }
    }
};
