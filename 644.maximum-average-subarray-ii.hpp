class Solution {
    const double EPS = 1e-5;
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double lo = INT_MAX, hi = INT_MIN;
        for(double x: nums) {
            lo = min(lo, x);
            hi = max(hi, x);
        }
        double prevMid = lo, err;
        do {
            double mid = lo + (hi - lo ) / 2;
            if(check(nums, mid, k)) {
                lo = mid;
            } else {
                hi = mid;
            }
            err = abs(mid - prevMid);
            prevMid = mid;
        } while(err >= EPS);
        return lo;
    }
    bool check(vector<int> &nums, double mid, int k) {
        int n = nums.size();
        double sum, prev, minPrev;
        sum = prev = minPrev = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i] - mid;
        }
        if(sum >= 0) return true;
        for(int i = k; i < n; i++) {
            sum += nums[i] - mid;
            prev += nums[i-k] - mid;
            minPrev = min(minPrev, prev);
            if(sum - minPrev >= 0)
                return true;
        }
        return false;
    }
};
