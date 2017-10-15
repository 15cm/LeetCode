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
        int ans = 0;
        unordered_map<int, unordered_map<int, int>> mp;
        for(int i = 0; i < n; i ++) {
            mp.clear();
            int overlap = 0, localMax = 0;
            for(int j = i + 1; j < n; j++) {
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                if(x == 0 && y == 0) {
                    overlap++;
                    continue;
                }
                int factor = gcd(x, y);
                if(factor) {
                    x /= factor;
                    y /= factor;
                }
                localMax = max(localMax, ++mp[x][y]);
            }
            ans = max(ans, localMax + overlap + 1);
        }
        return ans;
    }
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
