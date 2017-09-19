class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vis(n);
        int m = sqrt(n + 0.5);
        for(int i = 2; i <= m; i++)
            if(!vis[i])
                for(int j = i*i; j < n; j += i)
                    vis[j] = true;
        int cnt = 0;
        for(int i = 2; i < n; i++)
            if(!vis[i]) cnt++;
        return cnt;
    }
};
