class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = mysqrt(area);
        while(area % w) w--;
        return {area / w, w};
    }
    int mysqrt(int n) {
        if(n < 2) return n;
        int lo = 1, hi = n/2 + 1;
        while(true) {
            int mid = lo + (hi - lo) / 2;
            if(mid > n / mid) {
                hi = mid - 1;
            } else if(mid + 1 > n / (mid + 1)){
                return mid;
            } else {
                lo = mid + 1;
            }
        }
    }
};
