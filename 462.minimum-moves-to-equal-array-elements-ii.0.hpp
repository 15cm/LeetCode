class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int mid = quickSelection(0, n-1, n/2, nums);
        int ans = 0;
        for(int x: nums)
            ans += abs(x - nums[mid]);
        return ans;
    }
    int quickSelection(int lo, int hi, int k, vector<int>& A) {
        int p = partition(lo, hi, A);
        if(p == k) return p;
        else if(p < k) return quickSelection(p+1, hi, k, A);
        else return quickSelection(lo, p-1, k, A);
    }
    int partition(int lo, int hi, vector<int>& A) {
        int v = A[hi];
        int i = lo;
        for(int j = lo; j < hi; j++) {
            if(A[j] < v) {
                swap(A[i++], A[j]);
            }
        }
        swap(A[i], A[hi]);
        return i;
    }
};
