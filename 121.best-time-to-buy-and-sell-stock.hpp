class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, buy = 0;
        for(int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - prices[buy]);
            if(prices[i] < prices[buy]) buy = i;
        }
        return ans;
    }
};
