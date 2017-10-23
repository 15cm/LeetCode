class Solution {
    int m, n;
public:
    int numberOfPatterns(int m, int n) {
        this->m = m, this->n = n;
        vector<int> path;
        vector<bool> vis(9);
        int ans;
        path.push_back(0);
        vis[0] = true;
        ans += 4 * dfs(path, vis);
        path.pop_back();
        vis[0] = false;

        path.push_back(1);
        vis[1] = true;
        ans += 4 * dfs(path, vis);
        path.pop_back();
        vis[1] = false;

        path.push_back(4);
        vis[4] = true;
        ans += dfs(path, vis);
        return ans;
    }
    int dfs(vector<int>& path, vector<bool>& vis) {
        if(path.size() > n) {
            return 0;
        }
        int res = path.size() >= m ? 1 : 0;
        for(int i = 0; i < 9; i++) {
            if(!vis[i]) {
                if(!path.empty()) {
                    int crossed = cross(i, path.back());
                    if(crossed != -1 && !vis[crossed])
                        continue;
                }
                path.push_back(i);
                vis[i] = true;
                res += dfs(path, vis);
                path.pop_back();
                vis[i] = false;
            }
        }
        return res;
    }
    int cross(int a, int b) {
        int ra = a / 3, rb = b /3, ca = a % 3, cb = b %3;
        int diffR = abs(ra - rb), diffC = abs(ca - cb);
        if((ra == rb && diffC == 2) || (ca == cb && diffR == 2) || (diffR == 2 && diffC == 2)) {
            return (a + b) / 2;
        }
        return -1;
    }
};
