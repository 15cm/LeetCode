class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n = points.size();
        vector<bool> vis(n);
        vector<pair<int, int>> starts, ends;
        for(int i = 0; i < n; i++) {
            auto& p = points[i];
            starts.push_back({p.first, i});
            ends.push_back({p.second, i});
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int ans = 0;
        int ps = 0;
        for(auto& epr: ends) {
            if(vis[epr.second]) continue;
            ans++;
            int j = ps;
            for(; j < n && starts[j].first <= epr.first; j++) {
                vis[starts[j].second] = true;
            }
            ps = j;
        }
        return ans;
    }
};
