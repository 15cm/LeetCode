class Solution {
    int sum = 0;
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        dfs(A, A.size() - 1);
        return sum;
    }
    int dfs(vector<int>& A, int i) {
        if(i < 2) return 0;
        int res = 0;
        if(A[i] - A[i-1] == A[i-1] - A[i-2]) {
            res = 1 + dfs(A, i-1);
            sum += res;
        } else {
            dfs(A, i-1);
        }
        return res;
    }
};
