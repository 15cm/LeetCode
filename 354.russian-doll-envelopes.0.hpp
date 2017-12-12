class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto& arr = envelopes;
        if(arr.empty()) return 0;
        sort(arr.begin(), arr.end(), [](const auto& lhs, const auto& rhs) {
                return lhs.first < rhs.first || lhs.first == rhs.first && lhs.second > rhs.second;
            });
        int n = arr.size();
        vector<int> f(n);
        int i = 0;
        for(auto& pr: arr) {
            int x = pr.second;
            auto it = lower_bound(f.begin(), f.begin() + i, x);
            if(it - f.begin() == i) {
                f[i++] = x;
            } else {
                *it = x;
            }
        }
        return i;
    }
};
