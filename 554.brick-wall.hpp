#define maxn 20000
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if(wall.empty() || wall[0].empty()) return 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < wall.size(); i++) {
            for(int j = 0; j + 1 < wall[i].size(); j++) {
                mp[wall[i][j]]++;
                wall[i][j+1] += wall[i][j];
            }
        }
        int maxCnt = 0;
        for(auto& pr: mp) {
            maxCnt = max(maxCnt, pr.second);
        }
        return wall.size() - maxCnt;
    }
};
