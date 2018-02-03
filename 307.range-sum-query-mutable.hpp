class NumArray {
    vector<int> C, A;
    int n;
public:
    NumArray(vector<int> nums) {
        n = nums.size()+1;
        A = C = vector<int>(n);
        for(int i = 0; i < n-1; i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        i++;
        int x = val - A[i];
        A[i] = val;
        for(; i < n; i += (i & -i)) {
            C[i] += x;
        }
    }
    
    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }

    int getSum(int i) {
        i++;
        int sum = 0;
        for(; i > 0; i -= (i & -i)) {
            sum += C[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
