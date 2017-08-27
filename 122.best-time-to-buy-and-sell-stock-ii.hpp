class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int ans = 0;
        int lo = 0, pre = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < prices[i-1]) {
                ans += prices[i-1] - prices[lo];
                lo = i;
            }
        }
        ans += max(prices.back() - prices[lo], 0);
        return ans;
    }
};
