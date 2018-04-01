#define LL long long
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp.clear();
            for(int j = 0; j < n; j++) {
                if(i != j)
                    mp[calDis(points[i], points[j])]++;
            }
            for(auto& kv: mp) {
                int val = kv.second;
                if(val > 1)
                    ans += val * (val - 1);
            }
        }
        return ans;
    }
    int square(int x) {
        return x * x;
    }
    int calDis(const pair<int, int>& p, const pair<int, int>& q) {
        return square(p.first - q.first) + square(p.second - q.second);
    }
};
