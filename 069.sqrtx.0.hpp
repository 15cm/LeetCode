class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int lo = 1, hi = x/2 + 1;
        while(hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            int diff = mid - x / mid;
            if(diff > 0) {
                hi = mid - 1;
            } else if(diff == 0){
                return mid;
            } else {
                lo = mid + 1;
            }
        }
        int dlo = lo - x / lo;
        int dhi = hi - x / hi;
        if(dhi <= 0) {
            return hi;
        } else if(dlo <= 0){
            return lo;
        } else {
            return lo - 1;
        }
    }
};
