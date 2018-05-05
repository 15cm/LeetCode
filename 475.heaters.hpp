class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        set<int> st;
        for(int x: houses) st.insert(x);
        sort(heaters.begin(), heaters.end());
        int ans = max(0, heaters[0] - *st.begin());
        int n = heaters.size();
        for(int i = 1; i < n; i++) {
            int j = i - 1;
            int mid = (heaters[j] + heaters[i]) / 2;
            auto it = st.upper_bound(mid);
            if(prev(it) != st.end()) {
                ans = max(ans, *prev(it) - heaters[j]);
            }
            if(it != st.end()) {
                ans = max(ans, heaters[i] - *it);
            }
        }
        ans = max(ans, *st.rbegin() - heaters[n-1]);
        return ans;
    }
};
