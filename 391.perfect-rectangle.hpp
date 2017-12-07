struct pair_hash {
    size_t operator () (const pair<int, int>& pr) const{
        return pr.first * 31 + pr.second * 17;
    }
};
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int minX1 = INT_MAX, minY1 = INT_MAX, maxX2 = 0, maxY2 = 0;
        unordered_set<pair<int, int>, pair_hash> cnt;
        int area = 0;
        for(auto rec: rectangles) {
            int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];
            minX1 = min(minX1, x1);
            minY1 = min(minY1, y1);
            maxX2 = max(maxX2, x2);
            maxY2 = max(maxY2, y2);
            area += computeArea(x1, y1, x2, y2);

            vector<pair<int, int>> points = {
                {x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}
            };
            for(auto& p: points) {
                if(!cnt.count(p)) {
                    cnt.insert(p);
                } else {
                    cnt.erase(p);
                }
            }
        }
        if(cnt.size() != 4) return false;
        vector<pair<int, int>> points = {
            {minX1, minY1}, {minX1, maxY2}, {maxX2, minY1}, {maxX2, maxY2}
        };
        for(auto& p: points) {
            if(!cnt.count(p)) return false;
        }
        int maxArea = computeArea(minX1, minY1, maxX2, maxY2);
        return area == maxArea;
    }
    int computeArea(int x1, int y1, int x2, int y2) {
        return (x2 - x1) * (y2 - y1);
    }
};
