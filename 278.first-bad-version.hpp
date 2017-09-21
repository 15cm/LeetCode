// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return binarySearch(1, n);
    }
    int binarySearch(int lo, int hi) {
        if(lo == hi) return lo;
        int mid = lo + (hi - lo) / 2;
        if(isBadVersion(mid))
            return binarySearch(lo, mid);
        else
            return binarySearch(mid + 1, hi);
    }
};
