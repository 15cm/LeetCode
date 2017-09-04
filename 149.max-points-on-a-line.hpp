/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n < 2) return n;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            unordered_map<long double, int> mp;
            int overlap = 1;
            int vertical = 0;
            auto& p1 = points[i];
            for(int j = i + 1; j < n; j++) {
                auto& p2 = points[j];
                if(p1.x == p2.x) {
                    if(p1.y == p2.y) {
                        overlap++;
                    } else {
                        vertical++;
                    }
                } else {
                    long double slope = (p2.y - p1.y) * 10000.0 / (p2.x - p1.x);
                    if(!mp.count(slope)) mp[slope] = 1;
                    else mp[slope]++;
                }
            }
            ans = max(ans, vertical + overlap);
            for(auto& p: mp) {
                ans = max(ans, p.second + overlap);
            }
        }
        return ans;
    }
};
