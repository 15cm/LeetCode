class Solution {
public:
    int findNthDigit(int n) {
        vector<long> idxs;
        vector<int> nums;
        vector<int> steps;
        int step = 1;
        long idx = 0;
        for(long i = 1, j = 10; idx < INT_MAX; i *= 10, j *= 10, step++) {
            idx += (j - i) * step;
            nums.push_back(i);
            idxs.push_back(idx);
            steps.push_back(step);
        }
        auto it = lower_bound(idxs.begin(), idxs.end(), n);
        if(it != idxs.begin()) {
            n -= *(it-1);
        }
        int i = it - idxs.begin();
        int j = steps[i];
        int start = nums[i];
        n--;
        start += n / j;
        n %= j;
        return to_string(start)[n] - '0';
    }
};
