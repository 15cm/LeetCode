#define LL long long
class Solution {
    vector<LL> exps;
public:
    int largestPalindrome(int n) {
        for(int i = 0, exp = 1; i <= n; i++, exp *= 10)
            exps.push_back(exp);
        int limit = exps[n];
        for(LL i = limit - 1; i > 0; i--) {
            LL num = i * limit + rev(i);
            for(LL factor = sqrt(num); factor < limit; factor++) {
                if(num % factor == 0 && num / factor < limit)
                    return num % 1337;
            }
        }
        return limit - 1;
    }
    LL rev(LL num) {
        int res = 0;
        while(num > 0) {
            res *= 10;
            res += num % 10;
            num /= 10;
        }
        return res;
    }
};
