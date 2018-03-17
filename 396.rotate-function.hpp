class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            sum += A[i];
            ans += i * A[i];
        }

        int c = ans;
        for(int i = 0; i < n - 1; i++) {
            c = c - sum + n * A[i];
            ans = max(c, ans);
        }
        return ans;
    }
};
