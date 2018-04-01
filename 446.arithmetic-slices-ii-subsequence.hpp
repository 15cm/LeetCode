#define LL long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<LL, int>> f(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                LL diff = (LL)A[i] - A[j];
                int sum = f[j].count(diff) ? f[j][diff] : 0;
                ans += sum;
                f[i][diff] += sum + 1;
            }
        }
        return ans;
    }
};
