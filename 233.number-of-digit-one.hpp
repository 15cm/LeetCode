class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for(long m = 1; m <= n; m *= 10) {
            int a = n/m, b = n%m;
            res += (a+8)/10*m + (a % 10 == 1) * (b+1);
        }
        return res;
    }
};
