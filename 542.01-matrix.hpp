class Solution {
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return matrix;
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> q;
        int d = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) q.push(make_pair(i, j));
            }
        while(!q.empty()) {
            int sz = q.size();
            d--;
            while(sz--) {
                auto pr = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int x = pr.first + dx[i];
                    int y = pr.second + dy[i];
                    if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > 0) {
                        matrix[x][y] = d;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                matrix[i][j] = -matrix[i][j];
        return matrix;
    }
};
