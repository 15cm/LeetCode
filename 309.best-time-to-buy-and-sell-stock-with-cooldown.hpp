class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1) return 0;
        int prevBuy = 0, buy = -prices[0], prevSell = 0, sell = 0;
        for(int price: prices) {
            prevBuy = buy;
            buy = max(prevSell - price, prevBuy);
            prevSell = sell;
            sell = max(prevBuy + price, prevSell);
        }
        return sell;
    }
};
