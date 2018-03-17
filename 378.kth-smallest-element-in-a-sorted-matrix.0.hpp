class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1];
        int mid;
        while(lo < hi) {
            mid = lo + (hi-lo)/2;
            int cnt = 0;
            for(auto& row: matrix) {
                int p = upper_bound(row.begin(), row.end(), mid) - row.begin();
                cnt += p;
            }

            if(cnt < k) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
