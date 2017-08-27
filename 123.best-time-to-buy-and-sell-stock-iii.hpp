#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int K = 2, n = prices.size();
        vector<vector<int>> f(K + 1, vector<int>(n, 0));
        for(int k = 1; k <= K; k++) {
            int tmpMax = f[k - 1][0] - prices[0];
            for(int i = 1; i < n; i++) {
                f[k][i] = max(f[k][i - 1], prices[i] + tmpMax);
                tmpMax = max(f[k - 1][i] - prices[i], tmpMax);
            }
        }
        return f[K][n - 1];
    }
};
