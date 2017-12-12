class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto& arr = envelopes;
        if(arr.empty()) return 0;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;
        vector<int> f(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i].first > arr[j].first && arr[i].second > arr[j].second)
                    f[i] = max(f[i], f[j]);
            }
            f[i]++;
            ans = max(f[i], ans);
        }
        return ans;
    }
};
