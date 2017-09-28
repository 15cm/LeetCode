class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> factors;
        for(int i = 2; i <= n/2; i++) if(n % i == 0) factors.push_back(i);
        vector<vector<int>> ans;
        vector<int> stat(factors.size());
        dfs(0, stat, factors, n, ans);
        return ans;
    }
    void dfs(int cur, vector<int>& stat, vector<int>& factors, int target, vector<vector<int>>& ans) {
        if(cur == factors.size()) return;
        int factor = factors[cur];
        dfs(cur + 1, stat, factors, target, ans);
        for(int i = 1; target % factor == 0; i++) {
            target /= factor;
            stat[cur] = i;
            if(target == 1) {
                vector<int> tmp;
                for(int i = 0; i <= cur; i++)
                    for(int j = 0; j < stat[i]; j++)
                        tmp.push_back(factors[i]);
                ans.push_back(tmp);
                break;
            } else {
                dfs(cur + 1, stat, factors, target, ans);
            }
        }
        stat[cur] = 0;
    }
};
