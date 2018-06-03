class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> indexes(n);
        iota(indexes.begin(), indexes.end(), 0);
        stable_sort(indexes.begin(), indexes.end(), [&nums](int lhs, int rhs) {
                return nums[lhs] < nums[rhs];
            });
        vector<int> mins(n);
        mins[n - 1] = indexes[n-1];
        for(int i = n - 2; i >= 0; i--) {
            mins[i] = min(indexes[i], mins[i+1]);
        }
        int left = n, right = -1;
        for(int i = 0; i < n - 1; i++) {
            if(mins[i+1] < indexes[i]) {
                left = min(left, mins[i+1]);
                right = max(right, indexes[i]);
            }
        }
        return left == n ? 0 : right - left + 1;
    }
};
