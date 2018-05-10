class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> low;
        multiset<pair<int, int>> high;
        int n = Profits.size();
        for(int i = 0; i < n; i++) {
            if(Profits[i] > 0) {
                if(Capital[i] <= W) {
                    low.push(Profits[i]);
                } else {
                    high.emplace(Capital[i], Profits[i]);
                }
            }
        }
        while(k-- && !low.empty()) {
            W += low.top(); low.pop();
            for(auto it = high.begin(); it != high.end() && it->first <= W; it = high.erase(it))
                low.push(it->second);
        }
        return W;
    }
};
