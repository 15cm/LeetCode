class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if(M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size();
        int ans = 0;
        for(int i = 0; i < m ; i++) {
            int f = 0;
            for(int j = 0; j < n; j++) {
                f = M[i][j] ? f + 1 : 0;
                ans = max(f, ans);
            }
        }

        for(int j = 0; j < n; j++) {
            int f = 0;
            for(int i = 0; i < m; i++) {
                f = M[i][j] ? f + 1 : 0;
                ans = max(f, ans);
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            int r = 0, c = i, f = 0;
            while(r >= 0 && r < m && c >= 0 && c < n) {
                f = M[r][c] ? f + 1 : 0;
                ans = max(f, ans);
                r++;
                c++;
            }
        }

        for(int i = 1; i < m; i++) {
            int r = i, c = 0, f = 0;
            while(r >= 0 && r < m && c >= 0 && c < n) {
                f = M[r][c] ? f + 1 : 0;
                ans = max(f, ans);
                r++;
                c++;
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            int r = 0, c = i, f = 0;
            while(r >= 0 && r < m && c >= 0 && c < n) {
                f = M[r][c] ? f + 1 : 0;
                ans = max(f, ans);
                r++;
                c--;
            }
        }

        for(int i = 1; i < m; i++) {
            int r = i, c = n - 1, f = 0;
            while(r >= 0 && r < m && c >= 0 && c < n) {
                f = M[r][c] ? f + 1 : 0;
                ans = max(f, ans);
                r++;
                c--;
            }
        }

        return ans;
    }
};
