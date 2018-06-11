class Solution {
public:
    int smallestFactorization(int a) {
        if(a < 2) return a;
        long res = 0, exp = 1;
        for(int i = 9; i >= 2; i--) {
            while(a % i == 0) {
                res += i * exp;
                exp *= 10;
                a /= i;
            }
        }
        return (a == 1 && res <= INT_MAX) ? res : 0;
    }
};
