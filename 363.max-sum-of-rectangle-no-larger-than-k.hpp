class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();

        int ans = INT_MIN;
        for(int i = 0; i < m; i++) {
            vector<int> A(n);
            for(int j = i; j < m; j++) {
                for(int p = 0; p < n; p++) {
                    A[p] += matrix[j][p];
                }
                int cum = 0;
                set<int> cumset;
                cumset.insert(0);
                for(int l = 0; l < n; l++) {
                    cum += A[l];
                    auto it = cumset.lower_bound(cum - k);
                    if(it != cumset.end()) {
                        ans = max(ans, cum - *it);
                    }
                    cumset.insert(cum);
                }
            }
        }
        return ans;
    }
};
