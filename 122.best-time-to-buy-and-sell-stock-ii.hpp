class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int ans = 0, buy = 0, acc = 0;
        for(int i = 1; i < prices.size() - 1; i++) {
            if(prices[i] < prices[i-1]) {
                buy = i;
                ans += acc;
                acc = 0;
            }
            else {
                acc =  max(acc, prices[i] - prices[buy]);
            }
        }
        ans += max(acc, prices.back() - prices[buy]);
        return ans;
    }
};
