class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int n = timeSeries.size();
        for(int i = 0; i < n; i++) {
            ans += (i + 1 < n) ? min(duration, timeSeries[i+1] - timeSeries[i]) : duration;
        }
        return ans;
    }
};
