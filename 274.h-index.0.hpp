class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int n = citations.size();
        int cnt[n+1] = {0};
        for(int c: citations) {
            if(c >= n) cnt[n]++;
            else cnt[c]++;
        }
        int sum = 0;
        for(int i = n; i >= 0; i--) {
            sum += cnt[i];
            if(sum >= i) return i;
        }
        return 0;
    }
};
