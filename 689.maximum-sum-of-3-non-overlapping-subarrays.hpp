class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, K = k;
        int w[n-K+1];
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(i >= K) sum -= nums[i-K];
            if(i >= K-1) w[i-K+1] = sum;
        }
        int m = n - K + 1;
        int left[m];
        int best = 0;
        for(int i = 0; i < m; i++) {
            if(w[i] > w[best]) best = i;
            left[i] = best;
        }

        int right[m];
        best = m - 1;
        for(int i = m - 1 ; i >= 0; i--) {
            if(w[i] >= w[best]) best = i;
            right[i] = best;
        }

        vector<int> ans(3, -1);
        for(int j = K; j + K < m; j++) {
            int i = left[j - K], k = right[j + K];
            if(ans[0] == -1 || w[i] + w[j] + w[k] > w[ans[0]] + w[ans[1]] + w[ans[2]]) {
                ans[0] = i; ans[1] = j; ans[2] = k;
            }
        }
        return ans;
    }
};
