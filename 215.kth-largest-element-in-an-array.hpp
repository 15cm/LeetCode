class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickFind(nums, 0, nums.size() - 1, k);
    }
    int quickFind(vector<int>& nums, int lo, int hi, int k) {
        int p = partition(nums, lo, hi);
        int len = hi - p + 1;
        if(k > len)
            return quickFind(nums, lo, p - 1, k - len);
        else if(k < len)
            return quickFind(nums, p + 1, hi, k);
        else
            return nums[p];
    }
    int partition(vector<int>& nums, int lo, int hi) {
        int i = lo, j = hi + 1;
        int v = nums[lo];
        while(true) {
            while(nums[++i] < v) if(i == hi) break;
            while(nums[--j] > v) if(j == lo) break;
            if(i >= j) break;
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        return j;
    }
    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i]; nums[i] = nums[j]; nums[j] = t;
    }
};
