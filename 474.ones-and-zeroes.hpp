
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<int> c1(N), c2(N);
        for(int i = 0; i < N; i++) {
            for(char c: strs[i]) {
                if(c == '0') c1[i]++;
                else c2[i]++;
            }
        }

        vector<vector<int>> f(m+1, vector<int>(n+1));
        for(int i = 0; i < N; i++) {
            for(int u = m; u >= c1[i]; u--) {
                for(int v = n; v >= c2[i]; v--) {
                    f[u][v] = max(f[u][v], f[u - c1[i]][v - c2[i]] + 1);
                }
            }
        }
        return f[m][n];
    }
};
