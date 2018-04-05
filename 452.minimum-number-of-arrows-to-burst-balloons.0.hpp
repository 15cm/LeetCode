class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n = points.size();
        if(n == 0) return 0;
        sort(points.begin(), points.end(), [](const auto& lhs, const auto& rhs) {
                return lhs.second < rhs.second;
            });
        int ans = 1, pos = points[0].second;
        for(int i = 1; i < n; i++) {
            auto& p = points[i];
            if(p.first <= pos) continue;
            ans++;
            pos = p.second;
        }
        return ans;
    }
};
