class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 0) return 0;
        int lo = 1, hi = n;
        while(lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if(cmp(mid, n) <= 0) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if(cmp(lo, n) <= 0) {
            return lo;
        } else {
            return lo - 1;
        }
    }
    int cmp(int x, int n) {
        long diff = ((long) x * x + x) / 2 - n;
        return diff > 0 ? 1 : diff == 0 ? 0 : -1;
    }
};
