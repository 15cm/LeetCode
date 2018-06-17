#define LL long long
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i * i <= c / 2; i++) {
            if(isSqure(c - i * i)) return true;
        }
        return false;
    }
    bool isSqure(LL n) {
        LL lo = 0, hi = n / 2 + 1;
        while(lo < hi) {
            LL mid = lo + (hi - lo) / 2;
            LL diff = mid * mid - n;
            if(diff == 0) return true;
            else if(diff < 0) lo = mid + 1;
            else hi = mid;
        }
        return lo * lo == n;
    }
};
