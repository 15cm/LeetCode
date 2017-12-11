class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> f(amount+1, INT_MAX);
        f[0] = 0;
        for(int i = 1; i <= n; i++)
            for(int v = 0; v <= amount; v++) {
                if(v >= coins[i-1] && f[v-coins[i-1]] < f[v] - 1)
                    f[v] = f[v-coins[i-1]] + 1;
            }
        return f[amount] == INT_MAX ? -1 : f[amount];
    }
};
