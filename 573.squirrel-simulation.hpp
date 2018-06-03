class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int ans = 0, d = -(height + width);
        for(auto &nut: nuts) {
            ans += distance(tree, nut);
            d = max(d, distance(tree, nut) - distance(nut, squirrel));
        }
        return 2 * ans - d;
    }
    int distance(const vector<int> &p, const vector<int> &q) {
        return abs(p[0] - q[0]) + abs(p[1] - q[1]);
    }
};
