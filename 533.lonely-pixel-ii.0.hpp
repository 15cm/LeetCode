class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if(picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size();
        unordered_map<string, int> mp;
        vector<int> colCnt(n);

        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(picture[i][j] == 'B') {
                    colCnt[j]++;
                    cnt++;
                }
            }
            if(cnt == N) {
                mp[string(picture[i].begin(), picture[i].end())]++;
            }
        }

        int ans = 0;
        for(auto& pr: mp) {
            if(pr.second == N) {
                for(int j = 0; j < n; j++) {
                    if(pr.first[j] == 'B' && colCnt[j] == N) {
                        ans += N;
                    }
                }
            }
        }
        return ans;
    }
};
