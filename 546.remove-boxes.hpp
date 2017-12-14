class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        if(n == 0) return 0;
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n)));

        return dfs(0, n-1, 0, boxes, memo);
    }
    int dfs(int lo, int hi, int k, vector<int>& A, vector<vector<vector<int>>>& memo) {
        if(lo > hi) return 0;
        if(memo[k][lo][hi] > 0) return memo[k][lo][hi];
        int ans = (k+1)*(k+1) + dfs(lo+1, hi, 0, A, memo);
        for(int i = lo + 1; i <= hi; i++) {
            if(A[i] == A[lo]) {
                ans = max(ans, dfs(i, hi, k+1, A, memo) + dfs(lo + 1, i - 1, 0, A, memo));
            }
        }
        return memo[k][lo][hi] = ans;
    }
};
