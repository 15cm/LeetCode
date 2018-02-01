class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        if(n == 0) return;
        sums = vector<int>(n);
        for(int i = 0; i < n; i++) {
            sums[i] = nums[i] + (i > 0 ? sums[i-1] : 0);
        }
    }
    
    int sumRange(int i, int j) {
        return i > 0 ? sums[j] - sums[i-1] : sums[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
