// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return helper(1, n);
    }
    int helper(int lo, int hi) {
        if(lo == hi) return lo;
        int mid = lo + (hi - lo) / 2;
        if(isBadVersion(mid)) {
            return helper(lo, mid);
        } else {
            return helper(mid + 1, hi);
        }
    }
};
