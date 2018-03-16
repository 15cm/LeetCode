class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 4) return num == 1;
        int lo = 1, hi = num/2;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int t = num / mid;
            if(t == mid && num % mid == 0) return true;
            if(t < mid) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false;
    }
};
