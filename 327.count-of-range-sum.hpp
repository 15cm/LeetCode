class Solution {
    vector<long> aux;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> S(n+1);
        for(int i = 0; i < n; i++)
            S[i+1] = S[i] + nums[i];
        aux = vector<long>(n+1);
        return cntMergeSort(0, n+1, lower, upper, S);
    }

    int cntMergeSort(int left, int right, int lo, int up, vector<long>& S) {
        if(right - left <= 1) return 0;
        int mid = left + (right - left) / 2;
        int cnt = cntMergeSort(left, mid, lo, up, S) + cntMergeSort(mid, right, lo, up, S);
        int p = 0;
        for(int i = left, j = mid, k = mid, l = mid; i < mid; i++) {
            while(k < right && S[k] - S[i] < lo) k++;
            while(l < right && S[l] - S[i] <= up) l++;
            cnt += l - k;
            while(j < right && S[j] < S[i]) aux[p++] = S[j++];
            aux[p++] = S[i];
        }
        for(int i = 0; i < p; i++) {
            S[left + i] = aux[i];
        }
        return cnt;
    }
};
