class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        if(n < 10) {
            for(int i = 1; i<= n; i++) ans[i-1] = i;
            return ans;
        }
        int p = 0;
        int len = to_string(n).length();
        for(int i = 1; i < 10; i++) {
            dfs(i, p, 1, n, len, ans);
        }
        return ans;
    }
    bool dfs(int num, int& p, int depth, int n, int len, vector<int>& ans) {
        if(depth == len) {
            if(num <= n) {
                ans[p++] = num;
                return true;
            }
            return false;
        }
        ans[p++] = num;
        for(int i = 0; i < 10; i++) {
            if(!dfs(10*num + i, p, depth + 1, n, len, ans)) break;
        }
        return true;
    }
};
