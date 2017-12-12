class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int f = 10;
        for(int i = 2, k = 1; i <= min(10, n); i++) {
            k *= 11 - i;
            f += (i-1) * k + k * (10 - i);
        }
        return f;
    }
};
