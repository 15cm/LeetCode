// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int lo = 0, hi = INT_MAX;
        while(lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            int val = reader.get(mi);
            if(val > target)
                hi = mi - 1;
            else if(val < target)
                lo = mi + 1;
            else
                return mi;
        }
        return -1;
    }
};
