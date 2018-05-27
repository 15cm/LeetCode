class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if(picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size();
        vector<int> rcnt(m), ccnt(n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(picture[i][j] == 'B') {
                    rcnt[i]++;
                    ccnt[j]++;
                }
        int ans = 0;
        for(int j = 0; j < n; j++) {
            int i = 0;
            for(; i < m; i++) {
                if(picture[i][j] == 'W') continue;
                if(!(rcnt[i] == N && ccnt[j] == N)) {
                    i = -1;
                }
                break;
            }
            if(i < 0 || i >= m) continue;
            int cnt = 1;
            for(int k = i + 1; k < m; k++) {
                if(picture[k][j] == 'W') continue;
                if(picture[k] != picture[i]) {
                    cnt = 0;
                    break;
                }
                cnt++;
            }
            ans += cnt;
        }
        return ans;
    }
};
