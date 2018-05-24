class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if(picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size();
        vector<int> row(m, -1), col(n, -1);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(picture[i][j] == 'B') {
                    if(row[i] >= 0) {
                        row[i] = -1;
                        break;
                    }
                    row[i] = j;
                }
            }
        }
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                if(picture[i][j] == 'B') {
                    if(col[j] >= 0) {
                        col[j] = -1;
                        break;
                    }
                    col[j] = i;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++)
            if(row[i] >= 0 && col[row[i]] >= 0)
                ans++;
        return ans;
    }
};
