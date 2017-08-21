class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = 0;
        for(int i = 1; i < prices.size(); i++) {
            ans = max(prices[i] - prices[buy], ans);
            if(prices[i] < prices[buy]) buy = i;
        }
        return ans;
    }
};
