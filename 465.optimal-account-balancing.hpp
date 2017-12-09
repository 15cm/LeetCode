class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> mp;
        for(auto& txn: transactions) {
            mp[txn[0]] -= txn[2];
            mp[txn[1]] += txn[2];
        }
        vector<int> debt;
        for(auto& kv: mp) {
            if(kv.second)
                debt.push_back(kv.second);
        }
        return dfs(0, debt, 0);
    }
    int dfs(int p, vector<int>& debt, int cnt) {
        int n = debt.size();
        while(p < n && debt[p] == 0) p++;
        if(p == n) return cnt;
        int res = INT_MAX;
        unordered_set<int> memo;
        for(int i = p+1; i < n; i++) {
            if(!(debt[i] > 0 ^ debt[p] > 0) || memo.count(debt[i]))
                continue;
            memo.insert(debt[i]);
            debt[i] += debt[p];
            res = min(res, dfs(p+1, debt, cnt + 1));
            debt[i] -= debt[p];
        }
        return res;
    }
};
