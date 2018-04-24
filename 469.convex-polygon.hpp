#define pairint pair<int, int>
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        int dir = 0;
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (j + 1) % n;
            auto v1 = computeVec(points[i], points[j]), v2 = computeVec(points[j], points[k]);
            int rc = crossProductSign(v1, v2);
            if(rc == 0) continue;
            if(dir == 0) {
                dir = rc;
            } else if(dir != rc){
                return false;
            }
        }
        return true;
    }
    pairint computeVec(const vector<int>& p1, const vector<int>& p2) {
        return {p2[0] - p1[0], p2[1] - p1[1]};
    }
    int crossProductSign(const pairint& v1, const pairint& v2) {
        int rc = v1.first * v2.second - v1.second * v2.first;
        return rc == 0 ? 0 : rc > 0 ? 1 : -1;
    }
};
