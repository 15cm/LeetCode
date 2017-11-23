class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<vector<int>> f(n, vector<int>(k+1));

        for(int w = k - 1; w >= 0; w--) {
            for(int i = 0; i < n; i++) {
                f[i][w] = days[i][w] + f[i][w+1];
                for(int j = 0; j < n; j++) {
                    if(flights[i][j])
                        f[i][w] = max(f[i][w], days[j][w] + f[j][w+1]);
                }
            }
        }

        return f[0][0];
    }
};
