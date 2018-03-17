class Solution {
    unordered_map<int, int> memo;
public:
    int integerReplacement(int n) {
        memo[1] = 0;
        return dfs(n);
    }

    int dfs(long n) {
        int res;
        if(memo.count(n)) {
            return memo[n];
        }
        if(n & 1) {
            res = min(dfs(n+1), dfs(n-1)) + 1;
        } else {
            res = dfs(n/2) + 1;
        }
        return memo[n] = res;
    }
};
