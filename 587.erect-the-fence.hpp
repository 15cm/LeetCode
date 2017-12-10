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
    int orientation(const Point& p0, const Point& p1, const Point& p2) {
        // > 0: p1 else p2
        return (p1.y - p0.y)*(p2.x - p0.x) - (p2.y - p0.y)*(p1.x - p0.x);
    }
    int distance(const Point& p1, const Point& p2) {
        return pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2);
    }
public:
    vector<Point> outerTrees(vector<Point>& points) {
        if(points.size() < 3) return points;
        int bpidx = 0;
        int n = points.size();
        for(int i = 1; i < n; i++) {
            auto& bp = points[bpidx];
            auto& p = points[i];
            if(p.x < bp.x || p.x == bp.x && p.y < bp.y) {
                bpidx = i;
            }
        }
        swap(points[0], points[bpidx]);
        auto& bp = points[0];
        sort(points.begin() + 1, points.end(), [&bp, this](const Point& p, const Point& q) {
                int dir = orientation(bp, p, q);
                return dir == 0 ? distance(bp, p) < distance(bp, q) : dir > 0;
            });
        auto it = points.end() - 2;
        while(it > points.begin() + 1 && orientation(bp, *it, points.back()) == 0)
            it--;
        reverse(it+1, points.end());
        list<Point> l;
        for(int i = 0; i < 2; i++)
            l.push_front(points[i]);
        for(int i = 2; i < n; i++) {
            while(l.size() > 1 && orientation(*l.begin(), *next(l.begin()), points[i]) > 0)
                l.pop_front();
            l.push_front(points[i]);
        }
        return vector<Point>(l.rbegin(), l.rend());
    }
};
