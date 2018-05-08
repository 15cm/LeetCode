#define LL long long
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int>aux(n);
        return mergeSort(0, n - 1, nums, aux);
    }
    int mergeSort(int lo, int hi, vector<int>& A, vector<int>& aux) {
        if(lo == hi) return 0;
        int mid = lo + (hi - lo) / 2;
        int left = mergeSort(lo, mid, A, aux);
        int right = mergeSort(mid + 1, hi, A, aux);
        int cnt = 0;
        for(int i = lo, j = mid + 1; i <= mid; i++) {
            while(j <= hi && A[i] > (LL)2 * A[j])
                j++;
            cnt += j - (mid + 1);
        }
        merge(lo, mid, hi, A, aux);
        return cnt + left + right;
    }
    void merge(int lo, int mid, int hi, vector<int>& A, vector<int>& aux) {
        for(int i = lo, j = mid + 1, k = lo; k <= hi; k++) {
            if(i > mid || j <= hi && A[j] < A[i] ) aux[k] = A[j++];
            else aux[k] = A[i++];
        }
        for(int i = lo; i <= hi; i++)
            A[i] = aux[i];
    }
};
