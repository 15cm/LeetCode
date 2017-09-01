class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int ans = 0, n = ratings.size(), prev = 0;
        int trend = 0;
        vector<int> f(n, 1);
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                if(trend == -1) assignDesc(prev, i - 1, f, ratings);
                f[i] = f[i - 1] + 1;
                trend = 1;
            } else if(ratings[i] < ratings[i - 1]){
                if(trend == 1) prev = i;
                trend = -1;
            } else {
                if(trend == -1) assignDesc(prev, i - 1, f, ratings);
                prev = i;
                trend = 0;
            }
        }
        if(trend == -1) assignDesc(prev, n - 1, f, ratings);
        for(int i = 0; i < n; i++)
            ans += f[i];
        return ans;
    }
    void assignDesc(int prev, int tail, vector<int>& f, const vector<int> ratings) {
        for(int j = tail - 1; j >= prev; j--)
            f[j] = f[j + 1] + 1;
        if(prev > 0 && ratings[prev - 1] > ratings[prev] && f[prev - 1] <= f[prev])
            f[prev - 1] = f[prev] + 1;
    }
};
